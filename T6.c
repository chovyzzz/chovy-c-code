/****************************************************************************
 *                                                                          *
 * File    : main.c                                                         *
 *                                                                          *
 * Purpose : Console mode (command line) program.                           *
 *                                                                          *
 * History : Date      Reason                                               *
 *           00/00/00  Created                                              *
 *                                                                          *
 ****************************************************************************/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 100000
int a[SIZE],b[SIZE];

void InsertionSort(int *A, int n){
        int i;
	 int j;
	 int key;
        for (i=1;i<n;i++){
                key = *(A+i);//get value
                j=i-1;
                while(( j>=0) && (*(A+j)>key)) {//compare the number with previous number
                        *(A+j+1) = *(A+j);//put the previous number's previous number on the previous number position
                        j--;
                }
                *(A+j+1) = key;
        }
}

void merge(int* A,int low,int high,int mid) {
	int s[high - low + 1];//define a "dynamic" arr by incoming data
	int i = low; 
	int j = mid + 1;
	int sor = low;//control the new arr prevent it is influenced by a used number
	while (i <= mid && j <= high) {//put the data in the new arr
		if (A[i] < A[j]) {//determain the size of number
			s[sor++] = A[i++];
		}
		else {
			s[sor++] = A[j++];
		}
	}
	while (i <= mid) 
		s[sor++] = A[i++];
	while (j <= high)  
		s[sor++] = A[j++];
	sor = low;
	while (sor <= high) {//put new arr data in old arr
		A[sor] = s[sor];
		sor++;
	}
}


void merge_sort(int* A,int low,int high){
	if(low<high){
		int mid = (low + high) / 2;//find the middle position 
		merge_sort(A,low, mid);//divide the arr into 2 parts and use this function until it is not satisfied low < high then go to next instruction
		merge_sort(A, mid + 1, high);//divide the arr into 2 parts and use this function until it is not satisfied low < high then go to next instruction
		merge(A, low, high, mid);//uis merge to sort the divided arr
	}
}

int main(int argc, char *argv[])
{	int k[10]={3,6,2,5,8,97,5,2,4,0};
	clock_t time_begin,time_end;
	double result = 0;
	for (int i=0; i<=100000; i++){
    		a[i] = rand();
	}
	for (int i=0; i<=100000; i++){
    		b[i] = rand();
	}
	time_begin = clock();
	InsertionSort(b,100000);
	time_end = clock();
	result = (double)(time_end-time_begin)/CLOCKS_PER_SEC*1000;
	printf("\n\nRunning Time£º%fms\n",result);
   	time_begin = clock();
 	merge_sort(k, 0,9);
	time_end = clock();
 	for(int d = 0; d <= 9; d++){
 		printf("%d ", k[d]);
	}
	result = (double)(time_end-time_begin)/CLOCKS_PER_SEC*1000;
	printf("\n\nRunning Time£º%fms\n",result);
 	return 0; 
}

