#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
//https://leetcode.com/problems/valid-palindrome/description/
using namespace std;
class Solution {
public:

    
    bool isPalindrome(string s) {
        string afterFresh;
        for(auto it : s){
            if((97 <= it && it <= 122) || (48 <= it && it <= 57)){
               afterFresh.push_back(it); 
            }
            else if((65 <= it && it <= 90)){
                afterFresh.push_back(it + 32);
            }
            
        }
        //(afterFresh == "0zz0")? cout << "true" << endl : cout << "false" << endl;
        if(afterFresh =="") return true;
        if(afterFresh.size() == 1) return true;
        else{
            for(int i = 0; i < s.size() /2 ; i++){
                if(afterFresh[i] != afterFresh[afterFresh.size() - i - 1])return false;
                //else cout << "true";
            }   
            return true;
        }
    }
};
int main(){
    Solution so;
    string s = "0z;z   ; 0";
    (so.isPalindrome(s))? cout << "true" : cout << "false";
}