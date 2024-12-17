#include <stdio.h>
#include "../preview/preview.c"
#define ARRAY_SIZE 6

int finalTest[30] = {
    45, 12, 89, 32, 65, 71, 38, 24, 10, 99,
    53, 62, 18, 77, 84, 7, 21, 49, 91, 36,
    55, 43, 60, 74, 29, 3, 96, 81, 67, 40
};

int array[ARRAY_SIZE] = {7, 3, 9, 6, 5, 4};

void bubbleSort(int * arr, int len){
	int curIndex = 0;
	int rightPosition = 0;
	int mov;

	do {
		mov = 0;
		for(int i = 0; i < len - rightPosition -1; i++){
			if(arr[i] > arr[i+1]){
				int nextNumber = arr[i+1];
				arr[i+1] = arr[i];
				arr[i] = nextNumber;
				mov = 1;
			}
		}
	}while(mov == 1);
}

int main(){
	showArray(finalTest, 30);
	bubbleSort(finalTest, 30);
	showArray(finalTest, 30);
	
	return 0;
}

