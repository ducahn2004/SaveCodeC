#include <stdio.h>
#include <stdlib.h>
#include <iostream>
int main()
{
    int r = 3, c = 4, j, count;
 
    int** arr = (int**)malloc(r * sizeof(int*)); // declare a array to storage r pointer 0
    for (int i = 0; i < r; i++)
        *(arr+i) = (int*)malloc(c * sizeof(int));
 
    count = 0;
    for (int i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            *(*(arr+i)+j) = ++count;
 
    for (int i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            printf("%d ", *(*(arr +i)+j));
 
    /* Code for further processing and free the
       dynamically allocated memory */
 
    for (int i = 0; i < r; i++)
        free(arr+i);

    free(arr);
 
    return 0;

    int nRows = 3; int nCols = 4;
    int **matrix = new int*[nRows];
    for(int i = 0; i < nRows; i++){
        matrix[i] = new int[nCols];
    }
    for(int i = 0; i < nRows; i++){
        for(int j = 0; j < nCols; j++){
            std::cin >> *(*(matrix + i) + j);
        }
    }
    for(int i = 0; i < nRows; i++){
        delete[] matrix[i];
    }
    delete[] matrix;
}