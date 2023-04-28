#include <iostream>
#include <math.h>
#include <string>
#include <cstring>
using namespace std;

// int countWays(int n, int k) {
//     if (k == n) {
//         return 1;
//     }
//     if (k > n) {
//         return 0;
//     }
//     return countWays(n - k, k + 1) + countWays(n, k + 1);
// }

// int main() {
//    int x;
//    cin >> x;
//    cout << countWays(x, 1) << endl;
//    return 0;
// }
char *toString(int day,int month,int year){
    char* result = new char[10];
    if(day < 10){
        *(result) = '0';
        *(result + 1) = day + '0';
    }
    else{
        *(result) = day/10 + '0';
        *(result + 1) = day%10 + '0';
    }
    *(result + 2) = '/';
    if(month < 10){
        *(result + 3) = '0';
        *(result + 4) = month + '0';
    }
    else{
        *(result + 3) = month/10 + '0';
        *(result + 4) = month%10 + '0';
    }
    *(result + 5) = '/';
    int i = 0;
    while(i < 4){
        *(result + 9  - i) = year % 10 + '0';
        year = (year - year%10)/10; 
        i++; 
    }
    return result;
}
int main(){
    int day = 11;
    int month = 12;
    int year = 2023;
    char* result = new char[10];
    strcpy(result,toString(day,month,year));
    for(int i = 0; i < 10;i++){
        cout << *(result + i);
    }
}