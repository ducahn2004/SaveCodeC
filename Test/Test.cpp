#include<bits/stdc++.h>
using namespace std;


int main(){
    vector<int>a{4,2,4,6,1};
    int maxSum = 10;
    stack<int>stA;
    long long int sum = 0;
    int result = 0;
    for(int i = 0; i < a.size(); i++){
        if(sum + a[i] <= maxSum){
            stA.push(a[i]);
            result++;
            sum += a[i];
        }
    }
    stack<int>stB = stA;
    while(!stB.empty()){
        cout << stB.top() << " ";
        stB.pop();
    }
}