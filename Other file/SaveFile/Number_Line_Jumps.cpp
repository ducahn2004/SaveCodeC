/*
You are choreographing a circus show with various animals. For one act, you are given two kangaroos on a number line ready to jump in the positive direction (i.e, toward positive infinity).

The first kangaroo starts at x1 location  and moves at a rate of v1  meters per jump.
The second kangaroo starts at x2 location  and moves at a rate of v2 meters per jump.
You have to figure out a way to get both kangaroos at the same location at the same time as part of the show. If it is possible, return YES, otherwise return NO.

*/



#include <cmath> 
#include <cstdio> 
#include <map> 
#include <vector> 
#include <cstring> 
#include <iostream> 
#include <algorithm> 
#include <numeric> 
#include <stack> 
using namespace std; 
int main(){ 
    int x1; 
    int v1; 
    int x2; 
    int v2,dif; 
    cin >> x1 >> v1 >> x2 >> v2; 
    do { 
    dif=abs(x1-x2); 
    x1+=v1; 
    x2+=v2; 
    if(x1==x2) { 
        cout<<"YES"; 
        return 0; 
        } 
    }
    while(dif>abs(x1-x2)); 
    cout<<"NO"; 
    return 0;
}
