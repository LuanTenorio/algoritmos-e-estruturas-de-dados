#include <stdio.h>

void showArray(int *arr, int len){
	printf("[");
	for (int i = 0; i < len; ++i){
		printf("%d,", arr[i]);
	}
	printf("]\n");
}