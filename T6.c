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

/****************************************************************************
 *                                                                          *
 * Function: main                                                           *
 *                                                                          *
 * Purpose : Main entry point.                                              *
 *                                                                          *
 * History : Date      Reason                                               *
 *           00/00/00  Created                                              *
 *                                                                          *
 ****************************************************************************/
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
{
 int b[]={7,3,2,4,8,5};
 	int c;
	InsertionSort(b,6);
for(c = 0; c < 6; c++)
	{
 		printf("%d ", b[c]);
	}
	printf("\n");
    int a[]={3,9,5,4,64,4,5,9,8,9};
 	int i;
 	merge_sort(a, 0, 9);
 	for(i = 0; i < 10; i++)
	{
 		printf("%d ", a[i]);
	}
 	return 0; 
}

