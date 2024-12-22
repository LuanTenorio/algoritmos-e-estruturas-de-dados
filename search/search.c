#include <stdio.h>
#include "../array/array.h"
#include "search.h"

int linearSearch(Array *arr, int element){
    for (int i = 0; i < arr->length; i++){
        if(arr->data[i] == element) return i;
    }
    
    return -1;
}

int binarySearch(Array *arr, int element){
    int left = 0;
    int right = arr->length-1;
    int middle;

    while(right >= left){
        middle = (right - left) / 2 + left;
        int middleElement = arr->data[middle];
     
        if(element == middleElement)
            return middle;
        else if(element > middleElement)
            left = middle + 1;
        else
            right = middle - 1;
    }

    return -1;
}

int recursiveBinarySearch(Array *arr, int element, int left, int right){
    int middle = (right - left) /2 + left;
    int middleElement = arr->data[middle];
     
    if(element == middleElement)
        return middle;
    
    if(left == right)
        return -1;
    
    if(element > middleElement)
        return recursiveBinarySearch(arr, element, middle + 1, right);
    else
        return recursiveBinarySearch(arr, element, left, middle -1);
}

int main(){
    int arrData[7] = {1, 2, 3, 4, 5, 6, 7};
    Array arr = {arrData, 7};
    showArray(arr.data, arr.length);

    for (int i = 1; i <= 7; i++){
        printf("The position of %d is %d\n", i, recursiveBinarySearch(&arr, i, 0, arr.length-1));
        printf("The position of %d is %d\n", i, binarySearch(&arr, i));
    }
    
    return 0;
}