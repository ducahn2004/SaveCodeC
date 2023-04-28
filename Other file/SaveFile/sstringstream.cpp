//https://www.hackerrank.com/challenges/c-tutorial-stringstream/problem?isFullScreen=true
#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
    vector<int>result;
    stringstream s(str);
    int val;
    char ch;
    while(s >> val){
        result.push_back(val);
        s >> ch;  
    }
    return result;
}
int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}