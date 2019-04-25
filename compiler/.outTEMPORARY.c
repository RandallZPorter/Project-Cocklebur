 
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//Variables
double a = 0.0;
double b = 0.0;
double c = 0.0;
double d = 0.0;
double x = 0.0;
double y = 0.0;
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

void functionaddOne() {
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

void functionsubOne() {
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

void functionsubtractAux() {
do {
	c = popD();
	d = popD();
	pushD(c);
	functionsubOne();
	c = popD();
	pushD(d);
	functionsubOne();
	d = popD();
	pushD(d);
	pushD(c);
	pushD(0);
	pushD(d);
	} while (popD() > popD());
}

void functionsubtract() {
	functionsubtractAux();
	c = popD();
	d = popD();
	pushD(c);
}

void functionaddAux() {
do {
	c = popD();
	d = popD();
	pushD(c);
	functionaddOne();
	c = popD();
	pushD(d);
	functionsubOne();
	d = popD();
	pushD(d);
	pushD(c);
	pushD(0);
	pushD(d);
	} while (popD() > popD());
}

void functionadd() {
	functionaddAux();
	c = popD();
	d = popD();
	pushD(c);
}

void functionloop() {
while (1){
	x = popD();
	y = popD();
	pushD(y);
	
				printVar = popD();
				if (printVar == (int)printVar){
					printf("%d", (int)printVar);
				} else {
					printf("%lf", printVar);
				}
				
	printf("\n");
	fflush(stdout);
	pushD(x);
	pushD(y);
	pushD(x);
	functionadd();
	}
}


void main() {
	stack = createStack(1000);
	mathStack = createStack(1000);
	pushD(0);
	
				printVar = popD();
				if (printVar == (int)printVar){
					printf("%d", (int)printVar);
				} else {
					printf("%lf", printVar);
				}
				
	printf("\n");
	fflush(stdout);
	pushD(1);
	pushD(1);
	functionloop();
}


