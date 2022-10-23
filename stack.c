
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "stack.h"
bool IsEmpty(Stack* stack){
	if(stack->top == -1){//创建stack时定义top=-1当进行push后top的值会发生改变当top等于-1时表明stack为空
		return 1;
		}else{
		return 0;
		}
}


bool CreateStack(Stack *stack, int size){
	if(size <= 0)
		return false;
	stack->values = (double*)malloc(sizeof(double)*size);//动态申请大小为size的动态内存空间
	stack->top = -1;
	stack->maxTop = size - 1;//规定maxtop
	return true;
}


bool IsFull(Stack* stack){
	if(stack->top  == stack->maxTop){//当top+1等于size即等于maxtop时stack为满
		return 1;
	}else
		return 0;
}



bool Top(Stack* stack,double *x){
	if(IsEmpty(stack)){//通过IsEmpty判断stack是否为空
		return 0;
		}else{
		*x = (stack->values[stack->top]);//将top的值赋给x
		return 1;
		}
}

bool Push(Stack* stack, double x){
	if (IsFull(stack)){//通过IsFull判断stack是否满
		return 0;
	}else{	
		stack->values[(stack->top)+1] = x;//在top+1的位置上放入要加入的数值
		stack->top = stack->top + 1;//更新top的位置
		return 1;
	}
}


void DisplayStack(Stack *stack){
	int i = 0;
	printf("top -->");
	if(IsEmpty(stack)){//用IsEmpty判断stack是否为空
		printf("\t+----------+\n");
		printf("the linklist is empty!");//若为空打印出来提醒用户
	}else{
		for(i=stack->top; i>=0; i--){//通过for循环历尽stack中的值
			printf("\t|%10f|\n",stack->values[i]);
			}
		printf("\t+----------+\n");	
	}
}

bool Pop(Stack *stack,double *x){
	if (stack->top == -1){
		return 0;
	}else{
		stack->top = stack->top - 1;//改变top的指向
		*x = (stack->values[stack->top]);//将新的top的值赋给x
		return 1;
	}
}

void DestroyStack(Stack *stack){
	if (IsEmpty){
		printf("The LinkList is empty");
	}else{
		free(stack->values);//释放stack空间中的values
		free(stack);//释放stack空间
	DisplayStack(stack);
	}
}

