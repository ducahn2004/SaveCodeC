#include <iostream>
#include <string.h>
#include <cstring>
#include <cmath>
using namespace std;

struct Student{
    char msv[10];
    char name[100];
    char gpa[100];
};

double convert(char *arr);
void removeFirst(char *arr);
int main(){
    int n;
    cin >> n;
    fflush(stdin);
    double max = 0;
    int index = 0;
    Student *arr = new Student[n];
    for(int i = 0; i < n; i++){
        cin.getline((arr+i)->msv,10,',');
        cin.getline((arr+i)->name,100,',');
        cin >>(arr + i)->gpa;
        removeFirst((arr + i)->name);
        if(convert((arr + i)->gpa) > max){
            max = convert((arr + i)->gpa);
            index = i;
        }
    }
    cout << (arr + index)->name;
}
double convert(char *arr){
    double result = *(arr + 0) - '0';
    int length = strlen(arr);
    length-=2;
    int i = 2;
    while(length > 0){
        result += (*(arr + i) - '0')*pow(0.1,i-1);//pow(double ,double);
        length--;
        i++;
    }
    return result;
}
void removeFirst(char *arr){
    int length = strlen(arr);
    for(int i = 0; i <length - 1; i++){
        *(arr + i) = *(arr + i + 1);
    }
}