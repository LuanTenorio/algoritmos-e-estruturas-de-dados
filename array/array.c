#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "array.h"

void showArray(int *arr, int len){
	printf("[");
	for (int i = 0; i < len; ++i){
		printf("%d,", arr[i]);
	}
	printf("]\n");
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int arrayIsSorted(int *arr, int len){
	for (size_t i = 0; i < len-1; i++)
		if(arr[i] > arr[i+1]) 
			return 0;
	
	return 1;
}

void populateRandomIntArray(int *arr, int len){
	srand(time(NULL));
	for (size_t i = 0; i < len; i++){
		int random = rand() % 200;
		arr[i] = random;
	}
}