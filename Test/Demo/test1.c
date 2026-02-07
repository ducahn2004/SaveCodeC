#include <stdio.h>


//Declare function prototypes
//int myfoo(int);
//int ((*foo(int)))(int);


//Define functions
int myfoo(int a) {
    printf("Func: Myfoo\n");
    return a+1;
}

//Define function that returns a pointer to function
int (*foo(int a))(int) {
    printf("Func: myfoo = %p\n", myfoo);
    return myfoo;
}

//Variable to hold function pointer
int (*footpr)(int);

// Print 11
int main(){
    int a = 10;
    footpr = foo(a);
    printf("Main: footpr = %p\n", footpr);
    printf("Main: foo(a) = %p\n", foo(a));
    printf("Main:footpr(a) = %d\n", footpr(a));
    return 0;
}
