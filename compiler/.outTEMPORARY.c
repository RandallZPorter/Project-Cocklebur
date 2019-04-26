
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//Variables
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

void function1() {
while (1){
	pushD(1);
	
				printVar = popD();
				if (printVar == (int)printVar){
					printf("%d", (int)printVar);
				} else {
					printf("%lf", printVar);
				}
				
	printf("\n");
	fflush(stdout);
	}
}


void main() {
	stack = createStack(1000);
	mathStack = createStack(1000);
	pushD(0);
	pushD(1);
	if (popD() == popD()){
		function1();
	}
	pushD(0);
	
				printVar = popD();
				if (printVar == (int)printVar){
					printf("%d", (int)printVar);
				} else {
					printf("%lf", printVar);
				}
				
	printf("\n");
	fflush(stdout);
}


