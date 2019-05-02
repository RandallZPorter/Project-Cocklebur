
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//Variables
double vara = 0.0;
double varb = 0.0;
double vare = 0.0;
double varf = 0.0;
double varx = 0.0;
double con0 = 0.0;
double con1 = 0.0;
double printVar = 0.0;

//Functions
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
	if (isEmpty(stack)){ return 0.0; }
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

void function0() {
do {
	vara = popD();
	pushD(vara);
	pushD(0);
	con0 = popD();
	con1 = popD();
	if (con0){
		pushM(con0/con1);
	} else {
		con1 += (rand() % 2 == 0 ? 1 : -1);
		pushM(con1);
	}
	pushD(popM());
	varb = popD();
	pushD(vara);
	pushD(vara);
	pushD(varb);
	} while (popD() <= popD());
	vara = popD();
	pushD(varb);
}

void function1() {
do {
	vara = popD();
	pushD(vara);
	pushD(0);
	con0 = popD();
	con1 = popD();
	if (con0){
		pushM(con0/con1);
	} else {
		con1 += (rand() % 2 == 0 ? 1 : -1);
		pushM(con1);
	}
	pushD(popM());
	varb = popD();
	pushD(vara);
	pushD(vara);
	pushD(varb);
	} while (popD() >= popD());
	vara = popD();
	pushD(varb);
}

void function2() {
	vare = popD();
	varf = popD();
	pushD(1);
}

void function3() {
	vare = popD();
	varf = popD();
	pushD(0);
}

void function5() {
do {
	vare = popD();
	pushD(vare);
	function1();
	vare = popD();
	pushD(vare);
	pushD(0);
	pushD(vare);
	} while (popD() > popD());
}

void function4() {
	vare = popD();
	varf = popD();
	pushD(varf);
	pushD(vare);
	con0 = popD();
	con1 = popD();
	if (con0){
		pushM(con0/con1);
	} else {
		con1 += (rand() % 2 == 0 ? 1 : -1);
		pushM(con1);
	}
	pushD(popM());
	function5();
	vare = popD();
	pushD(vare);
	pushD(vare);
	pushD(0);
	pushD(vare);
	if (popD() == popD()){
		function2();
	}
	pushD(0);
	pushD(vare);
	if (popD() > popD()){
		function3();
	}
	pushD(0);
	pushD(vare);
	if (popD() < popD()){
		function3();
	}
}

void function6() {
	vare = popD();
	varf = popD();
	pushD(varf);
	pushD(vare);
	pushD(0);
	pushD(varf);
	if (popD() == popD()){
		function2();
	}
	pushD(1);
	pushD(varf);
	if (popD() == popD()){
		function2();
	}
	pushD(1);
	pushD(varf);
	if (popD() > popD()){
		function4();
	}
}

void function7() {
	pushD(102);
	
				printVar = popD();
				printf("%c", (char)(int)printVar);
				
	fflush(stdout);
	pushD(105);
	
				printVar = popD();
				printf("%c", (char)(int)printVar);
				
	fflush(stdout);
	pushD(122);
	
				printVar = popD();
				printf("%c", (char)(int)printVar);
				
	fflush(stdout);
	pushD(122);
	
				printVar = popD();
				printf("%c", (char)(int)printVar);
				
	fflush(stdout);
}

void function8() {
	pushD(98);
	
				printVar = popD();
				printf("%c", (char)(int)printVar);
				
	fflush(stdout);
	pushD(117);
	
				printVar = popD();
				printf("%c", (char)(int)printVar);
				
	fflush(stdout);
	pushD(122);
	
				printVar = popD();
				printf("%c", (char)(int)printVar);
				
	fflush(stdout);
	pushD(122);
	
				printVar = popD();
				printf("%c", (char)(int)printVar);
				
	fflush(stdout);
}

void function9() {
	pushD(varx);
	
				printVar = popD();
				if (printVar == (int)printVar){
					printf("%d", (int)printVar);
				} else {
					printf("%lf", printVar);
				}
				
	fflush(stdout);
}

void functiona() {
	pushD(5);
	pushD(varx);
	function6();
	pushD(0);
	if (popD() == popD()){
		function9();
	}
}

void functionb() {
do {
	varx = popD();
	pushD(3);
	pushD(varx);
	function6();
	pushD(1);
	if (popD() == popD()){
		function7();
	}
	pushD(5);
	pushD(varx);
	function6();
	pushD(1);
	if (popD() == popD()){
		function8();
	}
	pushD(3);
	pushD(varx);
	function6();
	pushD(0);
	if (popD() == popD()){
		functiona();
	}
	pushD(0);
	
				printVar = popD();
				printf("%c", (char)(int)printVar);
				
	printf("\n");
	fflush(stdout);
	pushD(varx);
	function0();
	varx = popD();
	pushD(varx);
	pushD(100);
	pushD(varx);
	} while (popD() <= popD());
}


void main() {
	stack = createStack(1000);
	mathStack = createStack(1000);
	pushD(1);
	functionb();
}


