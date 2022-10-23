#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "queue.h"

bool CreateQueue(Queue *queue, int size){
	if(size < 1) {
		printf("Error: size should be positive.\n");
		return 0;
}
	queue->values = (double*)malloc(sizeof(double)*size);
	queue->front = 0;
	queue->rear = -1;
	queue->counter = 0;
	queue->maxSize = size;
	return 1;
}
bool IsEmpty(Queue *queue){
	if(queue->counter == 0){//利用计数器判断是否为空
		return 1;
		}else{
		return 0; 
		}
	}
bool IsFull(Queue *queue){
	if(queue->counter == queue->maxSize){//利用计数器判断若计数器数值等于queue的大小则queue已满
		return 1;
		}else{
		return 0;
		}
	}
bool Enqueue(Queue *queue, double x){
	if(IsFull(queue)) {//先判断是否已满
		printf("Error: the queue is full.\n");
		return 0;
}
	queue->rear = (queue->rear+1) % queue->maxSize;//使queue可以循环（成为环状）
	queue->values[queue->rear] = x;//添加数值进入queue
	queue->counter++;//计数器加一
	return 1;
}
bool Dequeue(Queue *queue, double *x){
	if(IsEmpty(queue)){//先判断是否为空
        return 0;
    }else{
		*x = queue->values[queue->front];//先将要删掉的数字赋给X防止删除后无法找到数字
		queue->front = (queue->front + 1) % queue->maxSize;//使queue可以循环（成为环状）
		queue->counter--;//计数器减一
		return 1;
		}
}
void DisplayQueue(Queue *queue){
	printf("front-->");
	if(IsEmpty(queue)){//先判断是否为空
		printf(" <-- rear");
		printf("the queue is empty!");
	}else{
	int i = queue->front;
	int k = 0;
	while(k < queue->counter-1){
			if(queue->values[i] == queue->values[queue->front]){//若为头节点则无需在前面空格
				printf("%f\n ", queue->values[i]);
				}else
			printf("\t%8f\n ", queue->values[i]);
			i++;
			i %= queue->maxSize;//使queue可以循环（成为环状）
			k++;
			}
	printf("\t%8f <--rear", queue->values[i]);//最后一个数字
	printf("\n");
				}
			}

	
void DestroyQueue(Queue *queue){
	queue->maxSize = 0;
	free(queue->values);
	queue->front = queue->rear = -1;
	}
