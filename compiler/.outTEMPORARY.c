 
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


void main() {
	stack = createStack(1000);
	mathStack = createStack(1000);
	pushD(33);
	pushD(100);
	pushD(108);
	pushD(114);
	pushD(111);
	pushD(87);
	pushD(32);
	pushD(44);
	pushD(111);
	pushD(108);
	pushD(108);
	pushD(101);
	pushD(72);
	
				printVar = popD();
				printf("%c", (char)(int)printVar);
				
	fflush(stdout);
	
				printVar = popD();
				printf("%c", (char)(int)printVar);
				
	fflush(stdout);
	
				printVar = popD();
				printf("%c", (char)(int)printVar);
				
	fflush(stdout);
	
				printVar = popD();
				printf("%c", (char)(int)printVar);
				
	fflush(stdout);
	
				printVar = popD();
				printf("%c", (char)(int)printVar);
				
	fflush(stdout);
	
				printVar = popD();
				printf("%c", (char)(int)printVar);
				
	fflush(stdout);
	
				printVar = popD();
				printf("%c", (char)(int)printVar);
				
	fflush(stdout);
	
				printVar = popD();
				printf("%c", (char)(int)printVar);
				
	fflush(stdout);
	
				printVar = popD();
				printf("%c", (char)(int)printVar);
				
	fflush(stdout);
	
				printVar = popD();
				printf("%c", (char)(int)printVar);
				
	fflush(stdout);
	
				printVar = popD();
				printf("%c", (char)(int)printVar);
				
	fflush(stdout);
	
				printVar = popD();
				printf("%c", (char)(int)printVar);
				
	fflush(stdout);
	
				printVar = popD();
				printf("%c", (char)(int)printVar);
				
	printf("\n");
	fflush(stdout);
}


