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

    char formula(char a, char b, char &count){
        char result;
        if(a == '0' && b == '0'){
            result = '0';
            count = '0';
        }
        else if((a == '0' && b == '1') || (a == '1' && b == '0')){
            result = '1';
            count = '0';
        }
        else{
            result = '0';
            count = '1';
        }
        return result;
    }

    string addBinary(string a, string b) {
        string result = "";
        
        return result;
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