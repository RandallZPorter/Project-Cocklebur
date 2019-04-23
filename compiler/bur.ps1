param (
    [Parameter(Mandatory=$true)][string]$in,
    [Parameter(Mandatory=$true)][string]$out
)
#Clear-Host
$path = (Get-Location).ToString() + "\" #"C:\Users\s524409\Documents\44563\compiler\"
$codeIn = [char[]](-join (Get-Content ($path + <#"source.bur"#> $in)))
[System.Collections.ArrayList]$codeOut = @()

Function getObjectName($i) {
    $objName = ""
    while ($true){ 
        $i++
        $x = $codeIn[$i]
        if ([char[]]'~@#‽`!?*$' -notcontains $x){
            $objName += $x.ToString().Trim()
        } else {
            return $i, $objName
        }
    } 
    return $i, $objName
}

Function tab() {
    if ($indent){ $codeOut.Add("`t") | Out-Null }
}

$isComment = $false
for ($i = 0; $i -lt $codeIn.Count; $i++){
    $x = $codeIn[$i]
    if ($x -eq '"'){
        $isComment = -not $isComment
    }
    if (!$isComment -and $x -ne '"'){
        $codeOut.Add($x.ToString().Trim()) | Out-Null
    }
}

$codeIn = [char[]](-join $codeOut)
$codeOut.Clear()

$codeOut.Add(" 
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
`n") | Out-Null

$codeOut.Add("//Variables`n") | Out-Null
$codeOut.Add("`n//Functions") | Out-Null

$codeOut.Add("
struct Stack { 
	int top; 
	unsigned capacity; 
	double* array; 
}; 

struct Stack* createStack(unsigned capacity) { 
	struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack)); 
	stack->capacity = capacity; 
	stack->top = -1; 
	stack->array = (double*) malloc(stack->capacity * sizeof(double)); 
	return stack; 
} 

int isFull(struct Stack* stack) { 
    return stack->top == stack->capacity - 1; 
} 

int isEmpty(struct Stack* stack) { 
    return stack->top == -1; 
} 

void push(struct Stack* stack, double item) { 
	if (isFull(stack)){ return; }
	stack->array[++stack->top] = item;
} 

double pop(struct Stack* stack) { 
	if (isEmpty(stack)){ return /*INT_MIN;*/0.0; }
	return stack->array[stack->top--]; 
} 

struct Stack* stack;
struct Stack* mathStack;

void pushD(double item) {
    push(stack, item);
}
double popD() {
    return pop(stack);
}
void pushM(double item) {
    push(mathStack, item);
}
double popM() {
    return pop(mathStack);
}
`n") | Out-Null

$indent = $false
$inMain = $false
[System.Collections.ArrayList]$variables = @()
$funcNameDeclared = ""
[System.Collections.ArrayList]$infiniteLoops = @()
for ($i = 0; $i -lt $codeIn.Count; $i++){
    $x = $codeIn[$i]
    switch ($x){
        '~' { 
            $i++
            $x = $codeIn[$i]
            $retObject = getObjectName $i
            $i = $retObject[0]
            if ($x -eq '@') {
                $funcName = $retObject[1]
				$funcNameDeclared = $funcName
                if ($funcName -eq ','){
                    $codeOut.Add("`nvoid main() {`n") | Out-Null
                    $codeOut.Add("`tstack = createStack(1000);`n") | Out-Null
                    $codeOut.Add("`tmathStack = createStack(1000);`n") | Out-Null
                } else {
                    $codeOut.Add("void function$funcName() {`n") | Out-Null
                }
                $indent = $true
                $i--
            } elseif ($x -eq '$'){
                tab
                $x = $codeIn[$i]
                $varName = $retObject[1]
                if ($variables -notcontains $varName){
                    $variables.Add($varName) | Out-Null
                }
                if ($x -eq '?'){
                    $codeOut.Add("$varName = popD();`n") | Out-Null 
                } elseif ($x -eq '!'){
                    $codeOut.Add("pushD($varName);`n") | Out-Null 
                } else {
                    $codeOut.Add("`n") | Out-Null 
                }
            }
            break
        } '@' { 
            $retObject = getObjectName $i
            $i = $retObject[0]
			$funcName = $retObject[1]
			Write-Host "$funcNameDeclared called $funcName"
			if ($funcName -eq $funcNameDeclared){
				$n = $codeOut.IndexOf("void function$funcName() {`n")
		    	$declaration = "while (1){`n"
    			$codeOut.Insert($n + 1, $declaration)
	            tab;$codeOut.Add("}`n") | Out-Null
			} else {
	            tab;$codeOut.Add("function" + $funcName + "();`n") | Out-Null 
    		}
	        break
        } '#' { 
            $retObject = getObjectName $i
            $i = $retObject[0]
            $x = $codeIn[$i]
            if ($x -eq '!'){
                if ($indent){ $codeOut.Add("`t") | Out-Null }
                $codeOut.Add("pushD(" + $retObject[1] + ");`n") | Out-Null 
            }
            break
        } '‽' { 
            $i++
            $x = $codeIn[$i]
            switch ($x){
                '=' { $sign = '==' }
                ')' { $sign = '<' }
                '(' { $sign = '>' }
                ']' { $sign = '<=' }
                '[' { $sign = '>=' }
            }
            $retObject = getObjectName $i
            $i = $retObject[0]
            tab;$codeOut.Add("if (popD() $sign popD()){`n") | Out-Null 
            tab;$codeOut.Add("`tfunction" + $retObject[1] + "();`n") | Out-Null 
            tab;$codeOut.Add("}`n") | Out-Null 
            break
        } '`' { 
            tab;$codeOut.Add($t + "con0 = popD();`n") | Out-Null
            tab;$codeOut.Add($t + "con1 = popD();`n") | Out-Null 
            tab;$codeOut.Add($t + "if (con0){`n") | Out-Null
            tab;$codeOut.Add($t + "`tpushM(con0/con1);`n") | Out-Null 
            tab;$codeOut.Add($t + "} else {`n") | Out-Null 
            tab;$codeOut.Add($t + "`tcon1 += (rand() % 2 == 0 ? 1 : -1);`n") | Out-Null
            tab;$codeOut.Add($t + "`tpushM(con1);`n") | Out-Null 
            tab;$codeOut.Add($t + "}`n") | Out-Null
            break
        } '?' { 
            tab;$codeOut.Add("pushD(popM());`n") | Out-Null 
            break
        } ';' { 
            $indent = $false
            $codeOut.Add("}`n`n") | Out-Null 
            break
        } '!' { 
			$i += 2
			$x = $codeIn[$i]
			$isAscii = $x -eq '.'
			$i--
			$x = $codeIn[$i]
			$isAscii = $isAscii -or ($x -eq '.')
			$i--

			if ($isAscii){
				tab;$codeOut.Add("
				printVar = popD();
				printf(`"%c`", (char)(int)printVar);
				`n") | Out-Null
			} else {
				tab;$codeOut.Add("
				printVar = popD();
				if (printVar == (int)printVar){
					printf(`"%d`", (int)printVar);
				} else {
					printf(`"%lf`", printVar);
				}
				`n") | Out-Null
			}

			$i++
            $x = $codeIn[$i]
            if ($x -eq 'v'){
                tab;$codeOut.Add("printf(`"\n`");`n") | Out-Null
            }
            tab;$codeOut.Add("fflush(stdout);`n") | Out-Null
            break
        }
    }
}

$variables.Add("con0") | Out-Null
$variables.Add("con1") | Out-Null
$variables.Add("printVar") | Out-Null
$variables | ForEach-Object -Process {
    $i = $codeOut.IndexOf("`n//Functions")
    $declaration = "double $_ = 0.0;`n"
    $codeOut.Insert($i, $declaration)
}

$outPath = $path + ".outTEMPORARY.c"
$outValue = -join $codeOut
Set-Content -Path $outPath -Value $outValue

$compilePath = $path + $out #"out.exe"
"gcc $outPath -o $compilePath" | cmd
#rm $outPath
