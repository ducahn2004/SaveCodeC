//https://www.hackerrank.com/challenges/crush/problem?isFullScreen=false
//n is  the number of elements in the array,  
long arrayManipulation(int n,int q, int** queries) {
    long* arr_result = calloc(n,sizeof(long));
    int p = 0;
    while(p < q){
        for(int i = *(*(queries + p)) - 1 ; i <= *(*(queries + p) + 1) - 1 ; i++){
            *(arr_result + i ) += (long)*(*(queries + p) + 2);
        }
        p++;
    }
    long max = *(arr_result);
    for(int i = 0; i < n; i++){
        if(max < *(arr_result + i)){
            max = *(arr_result + i);
        }
    }
    return max;
}