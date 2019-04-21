 
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
double con0 = 0.0;
double con1 = 0.0;

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

void functionaddOneAux() {
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
	pushD(b);
	pushD(a);
	pushD(a);
	pushD(b);
	if (popD() <= popD()){
		functionaddOneAux();
	}
	a = popD();
	b = popD();
	a = popD();
	pushD(b);
	pushD(a);
}

void functionaddOne() {
	functionaddOneAux();
	a = popD();
}

void functionsubOneAux() {
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
	pushD(b);
	pushD(a);
	pushD(a);
	pushD(b);
	if (popD() >= popD()){
		functionsubOneAux();
	}
	a = popD();
	b = popD();
	a = popD();
	pushD(b);
	pushD(a);
}

void functionsubOne() {
	functionsubOneAux();
	a = popD();
}

void functionsubtractAux() {
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
	if (popD() > popD()){
		functionsubtractAux();
	}
}

void functionsubtract() {
	functionsubtractAux();
	c = popD();
	d = popD();
	pushD(c);
}

void functionaddAux() {
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
	if (popD() > popD()){
		functionaddAux();
	}
}

void functionadd() {
	functionaddAux();
	c = popD();
	d = popD();
	pushD(c);
}

void functionmodAux() {
	e = popD();
	f = popD();
	pushD(f);
	pushD(e);
	functionsubtract();
	e = popD();
	pushD(f);
	pushD(e);
	pushD(0);
	pushD(e);
	if (popD() > popD()){
		functionmodAux();
	}
}

void functionmod() {
	functionmodAux();
	functionadd();
}

void functiondivisible() {
	e = popD();
	f = popD();
	con0 = popD();
	con1 = popD();
	if (con0){
		pushM(con0/con1);
	} else {
		con1 += (rand() % 2 == 0 ? 1 : -1);
		pushM(con1);
	}
	pushD(popM());
}


void main() {
	stack = createStack(1000);
	mathStack = createStack(1000);
	pushD(10%3);
	printf("%lf", popD());
	printf("\n");
	fflush(stdout);
}


