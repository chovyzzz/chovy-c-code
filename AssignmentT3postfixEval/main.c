
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <ctype.h>
#include "EvalPostfix.h"




bool CreateStack(Stack *stack, int size) {
	  if(size < 1)
	    return false;
	  stack->values = (int*)malloc(sizeof(int) * size);
	  // The stack is initialized to be empty:
	  stack->top = -1;
	  stack->maxTop = size - 1;
	  return true;
}

bool IsEmpty(Stack *stack) {
  // The stack is empty when the stack's top index is equal to -1:
  return stack->top == -1;
}

bool IsFull(Stack *stack) {
  // The stack is full when the stack's top index is equal to the last index:
  return stack->top == stack->maxTop;
}

bool Push(Stack *stack, int x) {
  if(IsFull(stack))
    return false;
  // Add x to the stack.  top must be increased before we use it as an index:
  stack->values[++stack->top] = x;
  return true;
}

int Pop(Stack *stack) {
	int x;
  if(IsEmpty(stack))
    return false;
  // Pass the value of the top element to x.
  // top must be decreased after we use it as an index:
  x = stack->values[stack->top--];
  return x;
}

void EvalPostfix(char postfix[]){
    int i;
    char o;//o means operator
    int A;
    int B;
    int val;
    Stack  s;
    CreateStack(&s,50);
    for (i = 0; postfix[i] != 'e'; i++) {//evaluate postfix expression
        o = postfix[i];
        if (isdigit(o)) {//isdigit()can judge input is a number or not it is a bool function
            Push(&s,o - '0');//use "ch - '0'"is exchange the char into number 
        }
        else if (o == '+' || o == '-' || o == '*' || o == '/') {// pop top element A and next-to-top elemnet B from stack and compute B operator A
            A = Pop(&s);
            B = Pop(&s);

            switch (o)
            {
             case '*':
                val = B * A;
                break;

            case '/':
                val = B / A;
                break;

            case '+':
                val = B + A;
                break;

            case '-':
                val = B - A;
                break;
            }
            Push(&s,val);//push the value obtained above onto the stack
        	}
    }
    printf(" \n Result of expression evaluation : %d \n", Pop(&s));//give the result
}

int main(){
    	int i = 0;
    	char postfix[20];
	printf("PLEASE INPUT THE Postfix expression AND USE ',' SEPARATE EVERY NUMBER AND OPERATOR\N");
	printf("'e' IS THE END OF POSTFIX EXPRESSION WHICH MEAN WHEN YOU INPUT THE 'e' THE EXPRESSION IS END");
	for (i = 0; i <= 20 - 1; i++) {
       	scanf("%c", &postfix[i]);
		if (postfix[i] == 'e') {//set break point
            break;
        	} 
	    }
	    EvalPostfix(postfix); 
}


