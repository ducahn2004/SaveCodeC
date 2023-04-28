#include <stdio.h>
#define MaxN 100

void insert(int arr[] , int n ){
    for (int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }
}
void out(int arr[], int n){
    for (int i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void  swap(int *a, int *b){
    int temp  = *a;
    *a = *b;
    *b = temp;
}
void sort_increase(int arr[], int n){
    for(int i = 0; i < n ;i++){
        for(int j = 0; j < n - i -1; j++){
            if(arr[j] >  arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
void sort_decrease(int arr[], int n){
    for(int i = 0; i < n ;i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] < arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
int main(){
    int arr[MaxN];
    int arr_even[MaxN];
    int arr_odd[MaxN];
    int n;
    int count_even = 0;
    int count_odd = 0;
    printf("insert  n ");
    scanf("%d",&n);
    insert(arr,n);
    for (int i = 0; i < n; i++){
        if(arr[i] % 2 == 0){
            arr_even[count_even] = arr[i];
            count_even++;
        }
        else{
            arr_odd[count_odd] = arr[i];
            count_odd++;
        }
    }
    sort_increase(arr_even,count_even);
    sort_decrease(arr_odd,count_odd);
    out(arr_even,count_even);
    out(arr_odd,count_odd);
    return 0;
}