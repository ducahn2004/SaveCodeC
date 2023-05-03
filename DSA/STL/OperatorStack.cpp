#include <iostream>
#include <stack>
#include <vector>
using namespace std;


//vector a,b is ascending
//merge a,b -> c is ascending
// as merge sort algorithm
vector<int> stackConcat(vector<int> a, vector<int> b){
    stack<int> st1, st2;
    vector<int> v;
    for (int i = 0; i < a.size(); i++){
        st1.push(a[i]);
    }
    for (int i = 0; i < b.size(); i++){
        st2.push(b[i]);
    }
    stack<int> st3;
	while(!st1.empty() || !st2.empty()){
        if(st1.top() >= st2.top()){
            st3.push(st1.top());
            st1.pop();
        }
        else{
            st3.push(st2.top());
            st1.pop();
        }
    }
    while(!st1.empty()){
        st3.push(st1.top());
        st1.pop();
    }
    while(!st2.empty()){
        st3.push(st2.top());
        st2.pop();
    }
	while(!st3.empty()){
		v.push_back(st3.top());
		st3.pop();
	}
    return v;
}
vector<int> stickSpan(vector<int> arr);
int main(){
    stack<int>st;
    // st.push(1); // push in top stack
    // st.pop();  // pop in top stack
    // st.top(); // return element in top stack 
    // st.size(); // size of stack 
    // st.empty();// return true or false  
    vector<int>arr = {100,80,60,70,60,75,85};
    vector<int>res = stickSpan(arr);
    for(auto it = res.begin();it != res.end(); it++){
        cout << *it;
    }
}
//https://codelearn.io/learning/cpp-standard-template-library/47978 problem 40 stack
// as like insertion sort
vector<int> stickSpan(vector<int> arr)
{
    stack<int> st;
    vector < int > res;
    int n = arr.size();
    st.push(0); 
    res.push_back(1);

    for (int i = 1; i < n; i++) {
        while (!st.empty() && arr[st.top()] <= arr[i]) 
            st.pop(); 
        res.push_back((st.empty()) ? (i + 1) : (i - st.top())); 
        st.push(i); 
    }

    return res;
}
