#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    void addZero(string &a, string &b){
        if(a.size() > b.size()){
            while(a.size() > b.size()){
                b = "0" + b;
            }
        }
        else{
            while(a.size() < b.size()){
                a = "0" + a;
            }
        }
    } 

    

    string addBinary(string a, string b) {
    
    }
};
int main(){
    Solution so;
    string a = "11";
    string b = "1";
    so.addZero(a,b);
    //cout << a << " " << b;
    cout << so.addBinary(a,b);

}