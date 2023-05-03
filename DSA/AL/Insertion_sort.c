#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void insertion_Sort(int arr[], int arr_count)
{
    int i, key, j;
    for (i = 1; i < arr_count; i++) {
        key = arr[i];
        j = i - 1;
        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
int main(){
    int arr_count;
    /*scanf("%d",&arr_count);
    int *arr = (int*)malloc(arr_count*sizeof(int));
    for(int i = 0; i < arr_count; i++){
        scanf("%d",arr+i);
    }*/
    arr_count = 6;
    int arr[] = {6,3,5,7,8,2};
    insertion_Sort(arr,arr_count);
    for(int i= 0; i < arr_count; i++){
        printf("%d ",*(arr+i));
    }
    return 0;
    
}