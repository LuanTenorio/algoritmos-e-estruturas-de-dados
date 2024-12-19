#include <stdio.h>
#include "search.h"
#include "../array/array.c"

int linearSearch(Array *arr, int element){
    for (size_t i = 0; i < arr->length; i++){
        if(arr->data[i] == element) return i;
    }
    
    return -1;
}

int main(){
    int arrData[6] = {1, 2, 3, 4, 5, 6};
    Array arr = {arrData, 6};
    showArray(arr.data, arr.length);
    printf("The position of 3 is %d\n", linearSearch(&arr, 3));
    return 0;
}