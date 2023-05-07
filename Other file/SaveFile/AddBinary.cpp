// #include <iostream>
// #include <vector>
// #include <string>
// #include <algorithm>

// using namespace std;


// class Solution {
// public:
//     void addZero(string &a, string &b){
//         if(a.size() > b.size()){
//             while(a.size() > b.size()){
//                 b = "0" + b;
//             }
//         }
//         else{
//             while(a.size() < b.size()){
//                 a = "0" + a;
//             }
//         }
//     } 

//     char formula(char a, char b, char &count){
//         char result;
//         if(a == '0' && b == '0'){
//             result = '0';
//             count = '0';
//         }
//         else if((a == '0' && b == '1') || (a == '1' && b == '0')){
//             result = '1';
//             count = '0';
//         }
//         else{
//             result = '0';
//             count = '1';
//         }
//         return result;
//     }
    
//     string addBinary(string a, string b) {
//         addZero(a,b);
//         string result = "";
//         char count = '0';
//         for(int i = a.size() - 1; i >= 0; i--){
//             char temp_count;
//             char temp = formula(a[i],b[i],temp_count);
//             result += formula(temp,count,count);
//             count = formula(count, temp_count, temp_count);
//         }
//         if(count == '1') result.append("1");
//         reverse(result.begin(),result.end());
//         return result;
//     }
// };
// int main(){
//     Solution so;
//     // string a = "11";
//     // string b = "1";
//     string a;
//     string b;
//     cin >> a >> b;
//     //so.addZero(a,b);
//     //cout << a << " " << b;
//     cout << so.addBinary(a,b);

// }



//rescuion
#include <iostream>
using namespace std;

string addBinary(string a, string b) {
    if (a.empty())
        return b;
    if (b.empty())
        return a;

    int lastDigitA = a.back() - '0';
    int lastDigitB = b.back() - '0';
    int sumDigits = lastDigitA + lastDigitB;

    int carryOver = sumDigits / 2;
    int currentDigit = sumDigits % 2;

    a.pop_back();
    b.pop_back();

    string recursiveResult = addBinary(a, b);

    return recursiveResult + to_string(currentDigit);
}

int main() {
    string binary1 = "101";
    string binary2 = "110";

    string result = addBinary(binary1, binary2);
    cout << result << endl;  // Output: 1011

    return 0;
}
