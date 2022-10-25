#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "ValidBrackets.h"



bool CreateStack(Stack* stack, int size) {
    if (size < 1)
        return false;
    stack->str = (char*)malloc(sizeof(char) * size);
    // The stack is initialized to be empty:
    stack->top = -1;
    stack->maxTop = size - 1;
    return true;
}

bool IsFull(Stack* stack) {
    // The stack is full when the stack's top index is equal to the last index:
    return stack->top == stack->maxTop;
}

bool IsEmpty(Stack* stack) {
    // The stack is empty when the stack's top index is equal to -1:
    return stack->top == -1;
}
char Pop(Stack* stack) {
    char x;
    if (IsEmpty(stack))
        return false;
    // Pass the value of the top element to x.
    // top must be decreased after we use it as an index:
    x = stack->str[stack->top--];
    return x;
}

bool Push(Stack* stack, char x) {
    if (IsFull(stack))
        return false;
    // Add x to the stack.  top must be increased before we use it as an index:
    stack->str[++stack->top] = x;
    return true;
}


bool ValidBrackets(char* str) {
    int i = 0;
	int a = 0;
    Stack s;
    CreateStack(&s, 50);
    while (str[i] != '\0') {
		a++;
        if (str[i] == '(' || str[i] == '[' ){//Open parenthesis push encountered
            Push(&s, str[i]);
            //Every time an element is pushed, the next loop is performed, scanning the next character
        }else{//When a matching close bracket is encountered, the top left bracket is removed from the stack,With the if... else if...... The if structure ensures that for every matching close parenthesis scanned, only one matching character comes out of the stack, and the program that completes each judgment box goes through the next loop
            if(IsEmpty(&s)){
			return false;
			}
	     char a;
            a = Pop(&s);
            if (str[i] == ')' && a != '(') {
            		return false;
            }else if(str[i] == ']' && a != '[') {
                   return false;
            }else{
                    return true;
			}
        }
	i++;
    }
}


int main()
{

    char str[10] = { '(','[',')',')' };


    if (ValidBrackets(str)) {
        printf("True");
    }
    else {
        printf("False");
    }


    return 0;
}
