
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//Variables
double a = 0.0;
double b = 0.0;
double c = 0.0;
double d = 0.0;
double e = 0.0;
double f = 0.0;
double g = 0.0;
double h = 0.0;
double i = 0.0;
double x = 0.0;
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

void functiona() {
do {
	a = popD();
	pushD(a);
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
	b = popD();
	pushD(a);
	pushD(a);
	pushD(b);
	} while (popD() <= popD());
	a = popD();
	pushD(b);
}

void functionb() {
do {
	a = popD();
	pushD(a);
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
	b = popD();
	pushD(a);
	pushD(a);
	pushD(b);
	} while (popD() >= popD());
	a = popD();
	pushD(b);
}

void functionc() {
do {
	c = popD();
	d = popD();
	pushD(c);
	functionb();
	c = popD();
	pushD(d);
	functionb();
	d = popD();
	pushD(d);
	pushD(c);
	pushD(0);
	pushD(d);
	} while (popD() > popD());
}

void functiond() {
	functionc();
	c = popD();
	d = popD();
	pushD(c);
}

void functione() {
do {
	c = popD();
	d = popD();
	pushD(c);
	functiona();
	c = popD();
	pushD(d);
	functionb();
	d = popD();
	pushD(d);
	pushD(c);
	pushD(0);
	pushD(d);
	} while (popD() > popD());
}

void functionf() {
	functione();
	c = popD();
	d = popD();
	pushD(c);
}

void functiong() {
	e = popD();
	f = popD();
	pushD(1);
}

void function9() {
	e = popD();
	f = popD();
	pushD(0);
}

void function8() {
do {
	e = popD();
	pushD(e);
	functionb();
	e = popD();
	pushD(e);
	pushD(0);
	pushD(e);
	} while (popD() > popD());
}

void function7() {
	e = popD();
	f = popD();
	pushD(f);
	pushD(e);
	con0 = popD();
	con1 = popD();
	if (con0){
		pushM(con0/con1);
	} else {
		con1 += (rand() % 2 == 0 ? 1 : -1);
		pushM(con1);
	}
	pushD(popM());
	function8();
	e = popD();
	pushD(e);
	pushD(e);
	pushD(0);
	pushD(e);
	if (popD() == popD()){
		functiong();
	}
	pushD(0);
	pushD(e);
	if (popD() > popD()){
		function9();
	}
	pushD(0);
	pushD(e);
	if (popD() < popD()){
		function9();
	}
}

void function6() {
	e = popD();
	f = popD();
	pushD(f);
	pushD(e);
	pushD(0);
	pushD(f);
	if (popD() == popD()){
		functiong();
	}
	pushD(1);
	pushD(f);
	if (popD() == popD()){
		functiong();
	}
	pushD(1);
	pushD(f);
	if (popD() > popD()){
		function7();
	}
}

void function5() {
	pushD(1);
}

void function4() {
	pushD(0);
}

void function3() {
do {
	g = popD();
	h = popD();
	pushD(h);
	functiona();
	h = popD();
	pushD(h);
	pushD(g);
	pushD(h);
	pushD(g);
	function6();
	i = popD();
	pushD(0);
	pushD(i);
	} while (popD() == popD());
}

void function2() {
	g = popD();
	pushD(1);
	pushD(g);
	function3();
	g = popD();
	h = popD();
	pushD(h);
	pushD(g);
	if (popD() == popD()){
		function5();
	}
	pushD(h);
	pushD(g);
	if (popD() < popD()){
		function4();
	}
	pushD(h);
	pushD(g);
	if (popD() > popD()){
		function4();
	}
}

void function1() {
	pushD(x);
	
				printVar = popD();
				if (printVar == (int)printVar){
					printf("%d", (int)printVar);
				} else {
					printf("%lf", printVar);
				}
				
	printf("\n");
	fflush(stdout);
}

void function0() {
while (1){
	x = popD();
	pushD(x);
	function2();
	pushD(1);
	if (popD() == popD()){
		function1();
	}
	pushD(x);
	functiona();
	functiona();
	x = popD();
	pushD(x);
	}
}


void main() {
	stack = createStack(1000);
	mathStack = createStack(1000);
	pushD(2);
	
				printVar = popD();
				if (printVar == (int)printVar){
					printf("%d", (int)printVar);
				} else {
					printf("%lf", printVar);
				}
				
	printf("\n");
	fflush(stdout);
	pushD(3);
	function0();
}


