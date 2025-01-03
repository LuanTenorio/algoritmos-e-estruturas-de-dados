#include <stdio.h>
#include "../array/array.h"
#include "sort.h"
#define ARRAY_SIZE 6

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

int testerForRecursiveSort(void(*sortAlgorithm)(int*, int, int)){
	for(int i = 0; i < 20; i++){
		int len = 10+i;
		int arrayTest[len];
	 	populateRandomIntArray(arrayTest, len);
		sortAlgorithm(arrayTest, 0, len);
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
				swap(&arr[i+1], &arr[i]);
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
			swap(&arr[len - rightPosition++], &arr[biggerIndex]);
			mov = 1;
		}
	}while(mov == 1);
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int left = low;
    int right = high;

    while (left < right) {
        while (arr[left] <= pivot && left <= high - 1) 
            left++;

        while (arr[right] > pivot && right >= low + 1) 
            right--;
		
        if (left < right) 
            swap(&arr[left], &arr[right]);
    }

    swap(&arr[low], &arr[right]);
    return right;
}

void quickSort(int *arr, int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);

        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
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

	if(testerForRecursiveSort(quickSort)){
		printf("quickSort working\n");
	}else{
		printf("quickSort not working\n");
	}
}

int main(){

	checkAllSort();	

	return 0;
}
