#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "../preview/preview.c"
#define ARRAY_SIZE 6

int finalTest[30] = {
    45, 12, 89, 32, 65, 71, 38, 24, 10, 99,
    53, 62, 18, 77, 84, 7, 21, 49, 91, 36,
    55, 43, 60, 74, 29, 3, 96, 81, 67, 40
};

int array[ARRAY_SIZE] = {7, 3, 9, 6, 5, 4};

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

int testerSort(void(*sortAlgorithm)(int*, int)){
	for(int i = 0; i < 20; i++){
		int len = 10+i;
		int arrayTest[len];
	 	populateRandomIntArray(arrayTest, len);
		sortAlgorithm(arrayTest, len);
		if(!arrayIsSorted(arrayTest, len))
			return 0;
	}
	return 1;
}

void bubbleSort(int * arr, int len){
	int curIndex = 0;
	int rightPosition = 1;
	int mov;

	do {
		mov = 0;
		for(int i = 0; i < len - rightPosition; i++){
			if(arr[i] > arr[i+1]){
				int nextNumber = arr[i+1];
				arr[i+1] = arr[i];
				arr[i] = nextNumber;
				mov = 1;
			}
		}
	}while(mov == 1);
}

void selectionSort(int * arr, int len){
	int rightPosition = 1;
	int biggerIndex = 0;
	int mov;

	do {
		mov = 0;
		biggerIndex = 0;
		for(int i = 1; i <= len -rightPosition; i++){
			if(arr[biggerIndex] < arr[i]){
				biggerIndex = i;
			}
		}

		if(biggerIndex != len - rightPosition +1){
			int lastNumber = arr[len - rightPosition];
			arr[len - rightPosition++] = arr[biggerIndex];
			arr[biggerIndex] = lastNumber;
			mov = 1;
		}
	}while(mov == 1);
}

void checkAllSort(){
	if(testerSort(bubbleSort)){
		printf("bubbleSort working\n");
	}else{
		printf("bubbleSort not working\n");
	}

	if(testerSort(selectionSort)){
		printf("selectionSort working\n");
	}else{
		printf("selectionSort not working\n");
	}
}

int main(){

	checkAllSort();	

	return 0;
}
