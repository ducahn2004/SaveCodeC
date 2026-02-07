#include "stdio.h"

int add2Int(int a, int b) {
    return a + b;
}
int subtract2Int(int a, int b) {
    return a - b;
}
int multiply2Int(int a, int b) {
    return a * b;
}
int divide2Int(int a, int b) {
    return a / b;
}
void printfFunc(int (*calc1)(int,int), int (*calc2)(int,int), int x, int y) {
    printf("x: %d, y : %d\nSum: %d\nDifference: %d\n", x, y, (*calc1)(x,y), (*calc2)(x,y));
}
int main(){
    int (*fp)(int, int) = add2Int;// fp points to function add2Int
    printf("Sum: %d\n", fp(10, 20));
    printfFunc(add2Int, subtract2Int, 10, 2);
    printfFunc(multiply2Int, divide2Int, 10, 2);
    printfFunc(add2Int, divide2Int, 10, 2);
    printfFunc(multiply2Int, subtract2Int, 10, 2);
}