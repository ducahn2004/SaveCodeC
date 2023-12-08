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
struct BigNumber {
    int a[50000];

    void init(int x) {
        memset(a, 0, sizeof(a));
        a[0] = 1;
        a[1] = x;
    }

    void write() {
        printf("%d", a[a[0]]);
        FORD(i, a[0] - 1, 1) {
            for (int j = int(1e8); j > 1 && j > a[i]; j /= 10)
                printf("0");
            printf("%d", a[i]);
        }
    }
};

BigNumber add(BigNumber x, BigNumber y) {
    x.a[0] = max(y.a[0], x.a[0]);
    FOR(i, 1, x.a[0]) {
        int sum = x.a[i] + y.a[i];
        x.a[i] = sum % MOD;
        x.a[i + 1] += sum / MOD;
    }
    x.a[0] += (x.a[x.a[0] + 1] > 0);
    return x;
}

BigNumber multiply(BigNumber x, BigNumber y) {
    BigNumber t;
    t.init(0);
    FOR(j, 1, y.a[0])
        FOR(i, 1, x.a[0]) {
            ll pro = 1LL * y.a[j] * x.a[i] + t.a[j + i - 1];
            t.a[j + i] += pro / MOD;
            t.a[j + i - 1] = pro % MOD;
        }
    t.a[0] = x.a[0] + y.a[0] + 5;
    while (t.a[t.a[0]] == 0 && t.a[0] > 1)
        t.a[0]--;
    return t;
}
int main(){
    string a, b;
    input(a);
    input(b);   
    output(a);
    output(b);
}