#include <bits/stdc++.h>
using namespace std;

typedef string bigNumber;
void input(bigNumber &number){
    cin >> number;
}

void output(bigNumber number){
    cout << number;
}
void equal_length(bigNumber &a, bigNumber &b)
{
    while (a.size() < b.size())
        a = '0' + a;
    while (b.size() < a.size())
        b = '0' + b;
}
        
int compare(bigNumber a, bigNumber b)
{
    equal_length(a, b);
    
    if (a < b) // Có thể là a <= b.
        return -1;
    if (a > b) // Có thể là a >= b.
        return 1;

    return 0;
}
bigNumber add(bigNumber a, bigNumber b)
{
    equal_length(a, b);
    
    int carry = 0;
    bigNumber res;
    for (int i = a.size() - 1; i >= 0; --i){
        // Cộng hai chữ số cùng hàng và thêm biến nhớ từ hàng bên phải dồn lên.
        int d = (a[i] - '0') + (b[i] - '0') + carry;
        
        carry = d / 10; // Biến nhớ bằng kết quả hàng trước chia 10.
        res = (char)(d % 10 + '0') + res; // Viết chữ số cuối của kết quả.
    }
    
    if (carry) res = '1' + res;
        
    return res;
}

int main(){
    string a, b;
    input(a);
    input(b);   
    output(a);
    output(b);
}