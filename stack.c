
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "stack.h"
bool IsEmpty(Stack* stack){
	if(stack->top == -1){//����stackʱ����top=-1������push��top��ֵ�ᷢ���ı䵱top����-1ʱ����stackΪ��
		return 1;
		}else{
		return 0;
		}
}


bool CreateStack(Stack *stack, int size){
	if(size <= 0)
		return false;
	stack->values = (double*)malloc(sizeof(double)*size);//��̬�����СΪsize�Ķ�̬�ڴ�ռ�
	stack->top = -1;
	stack->maxTop = size - 1;//�涨maxtop
	return true;
}


bool IsFull(Stack* stack){
	if(stack->top  == stack->maxTop){//��top+1����size������maxtopʱstackΪ��
		return 1;
	}else
		return 0;
}



bool Top(Stack* stack,double *x){
	if(IsEmpty(stack)){//ͨ��IsEmpty�ж�stack�Ƿ�Ϊ��
		return 0;
		}else{
		*x = (stack->values[stack->top]);//��top��ֵ����x
		return 1;
		}
}

bool Push(Stack* stack, double x){
	if (IsFull(stack)){//ͨ��IsFull�ж�stack�Ƿ���
		return 0;
	}else{	
		stack->values[(stack->top)+1] = x;//��top+1��λ���Ϸ���Ҫ�������ֵ
		stack->top = stack->top + 1;//����top��λ��
		return 1;
	}
}


void DisplayStack(Stack *stack){
	int i = 0;
	printf("top -->");
	if(IsEmpty(stack)){//��IsEmpty�ж�stack�Ƿ�Ϊ��
		printf("\t+----------+\n");
		printf("the linklist is empty!");//��Ϊ�մ�ӡ���������û�
	}else{
		for(i=stack->top; i>=0; i--){//ͨ��forѭ������stack�е�ֵ
			printf("\t|%10f|\n",stack->values[i]);
			}
		printf("\t+----------+\n");	
	}
}

bool Pop(Stack *stack,double *x){
	if (stack->top == -1){
		return 0;
	}else{
		stack->top = stack->top - 1;//�ı�top��ָ��
		*x = (stack->values[stack->top]);//���µ�top��ֵ����x
		return 1;
	}
}

void DestroyStack(Stack *stack){
	if (IsEmpty){
		printf("The LinkList is empty");
	}else{
		free(stack->values);//�ͷ�stack�ռ��е�values
		free(stack);//�ͷ�stack�ռ�
	DisplayStack(stack);
	}
}

