#include <iostream>
#include <queue>
#include <vector>
using namespace std;

//return binary list 1->n 
//  n = 2 generateBinary = ["1","10"]
//  n = 5 generateBinary = ["1", "10","11", "100", "101"]
vector<string> generateBinary(int n){
    vector<string>res;
    queue<string>q;
    q.push("1");
    while(n--){ // ? while n-- is break 
        q.push(q.front() + "0");
        q.push(q.front() + "1");
        res.push_back(q.front());
        q.pop();
    }
    return res;
}
// 49 Queue code learn 
vector<int> firstNegative(vector<int> a, int k)
{
    queue<int> st;
    int n = a.size();
    for (int i = 0; i < k - 1; i++) {
        if (a[i] < 0) st.push(i);
    }
    vector<int> res;
    for (int i = k - 1; i < n; i++) {
        if (a[i] < 0) st.push(i);
        while (!st.empty() && st.front() < i - k + 1) st.pop();
        res.push_back(st.empty() ? 0 : a[st.front()]);
    }
    return res;
}
int main(){
    queue<int>qe;
    qe.size();    // return size of queue
    qe.empty();  // return true if queue empty and false if queue is not empty
    qe.front(); // return the first element is added to queue
    qe.back(); // return the last element is added to queue
    int x;
    qe.push(x); // add a element to last queue
    qe.pop();  // delete first element in queue

}