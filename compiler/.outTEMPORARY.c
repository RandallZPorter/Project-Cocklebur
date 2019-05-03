
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//Variables
double vara = 0.0;
double varb = 0.0;
double varc = 0.0;
double vard = 0.0;
double vare = 0.0;
double varf = 0.0;
double varg = 0.0;
double varh = 0.0;
double vari = 0.0;
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

void functionaddOne() {
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

void functionsubOne() {
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

void functionsubtractAux() {
do {
	varc = popD();
	vard = popD();
	pushD(varc);
	functionsubOne();
	varc = popD();
	pushD(vard);
	functionsubOne();
	vard = popD();
	pushD(vard);
	pushD(varc);
	pushD(0);
	pushD(vard);
	} while (popD() > popD());
}

void functionsubtract() {
	functionsubtractAux();
	varc = popD();
	vard = popD();
	pushD(varc);
}

void functionaddAux() {
do {
	varc = popD();
	vard = popD();
	pushD(varc);
	functionaddOne();
	varc = popD();
	pushD(vard);
	functionsubOne();
	vard = popD();
	pushD(vard);
	pushD(varc);
	pushD(0);
	pushD(vard);
	} while (popD() > popD());
}

void functionadd() {
	functionaddAux();
	varc = popD();
	vard = popD();
	pushD(varc);
}

void functiondivisableTRUE() {
	vare = popD();
	varf = popD();
	pushD(1);
}

void functiondivisableFALSE() {
	vare = popD();
	varf = popD();
	pushD(0);
}

void functiondivisableLOOP() {
do {
	vare = popD();
	pushD(vare);
	functionsubOne();
	vare = popD();
	pushD(vare);
	pushD(0);
	pushD(vare);
	} while (popD() > popD());
}

void functiondivisableELSE() {
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
	functiondivisableLOOP();
	vare = popD();
	pushD(vare);
	pushD(vare);
	pushD(0);
	pushD(vare);
	if (popD() == popD()){
		functiondivisableTRUE();
	}
	pushD(0);
	pushD(vare);
	if (popD() > popD()){
		functiondivisableFALSE();
	}
	pushD(0);
	pushD(vare);
	if (popD() < popD()){
		functiondivisableFALSE();
	}
}

void functiondivisable() {
	vare = popD();
	varf = popD();
	pushD(varf);
	pushD(vare);
	pushD(0);
	pushD(varf);
	if (popD() == popD()){
		functiondivisableTRUE();
	}
	pushD(1);
	pushD(varf);
	if (popD() == popD()){
		functiondivisableTRUE();
	}
	pushD(1);
	pushD(varf);
	if (popD() > popD()){
		functiondivisableELSE();
	}
}

void functionprimeTRUE() {
	pushD(1);
}

void functionprimeFALSE() {
	pushD(0);
}

void functionprimeLOOP() {
do {
	varg = popD();
	varh = popD();
	pushD(varh);
	functionaddOne();
	varh = popD();
	pushD(varh);
	pushD(varg);
	pushD(varh);
	pushD(varg);
	functiondivisable();
	vari = popD();
	pushD(0);
	pushD(vari);
	} while (popD() == popD());
}

void functionprime() {
	varg = popD();
	pushD(1);
	pushD(varg);
	functionprimeLOOP();
	varg = popD();
	varh = popD();
	pushD(varh);
	pushD(varg);
	if (popD() == popD()){
		functionprimeTRUE();
	}
	pushD(varh);
	pushD(varg);
	if (popD() < popD()){
		functionprimeFALSE();
	}
	pushD(varh);
	pushD(varg);
	if (popD() > popD()){
		functionprimeFALSE();
	}
}

void functionprintALL() {
do {
	varx = popD();
	pushD(varx);
	
				printVar = popD();
				if (printVar == (int)printVar){
					printf("%d", (int)printVar);
				} else {
					printf("%lf", printVar);
				}
				
	printf("\n");
	fflush(stdout);
	pushD(0);
	pushD(varx);
	} while (popD() > popD());
}

void functionloop() {
do {
	functionsubOne();
	varx = popD();
	pushD(varx);
	pushD(varx);
	pushD(2);
	pushD(varx);
	} while (popD() > popD());
}


void main() {
	stack = createStack(1000);
	mathStack = createStack(1000);
	pushD(20);
	functionloop();
	varx = popD();
	functionprintALL();
}


