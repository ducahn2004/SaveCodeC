#include <bits/stdc++.h>
using namespace std;

typedef vector < int > vi;
istream &operator >> (istream &cin, vi &number){
    string s;
    cin >> s;

    number.clear();
    for (int i = 0; i < s.size(); ++i)
        number.push_back(s[i] - '0');

    return cin;
}
ostream &operator << (ostream &cout, const vi &a) {
    for (auto d: a) 
        cout << d;

    return cout;
} 
// Viết thêm các số 0 ở đầu.
void add_zero(vi &a, int sz) 
{
    // Đầu tiên đảo ngược số để tối ưu thời gian khi thêm phần tử.
    reverse(a.begin(), a.end()); 
    
    while (a.size() < sz) 
        a.push_back(0); 
	
    reverse(a.begin(), a.end());
}

// Đưa 2 số về cùng một size bằng các push các số 0 lên đầu.
void change(vi &a, vi &b) 
{ 
    int sz = max(a.size(), b.size());
    add_zero(a, sz);
    add_zero(b, sz);
}

bool operator < (vi a, vi b) 
{
    change(a, b);

    for (int i = 0; i < a.size(); ++i) 
        if (a[i] < b[i]) 
            return true;
        else if (a[i] > b[i]) 
            return false;
	
    return false;
}

bool operator > (vi a, vi b) 
{
    change(a, b);
	
    for (int i = 0; i < a.size(); ++i) 
        if (a[i] > b[i]) 
            return true;
        else if (a[i] < b[i]) 
            return false;

    return false;
}

bool operator <= (vi a, vi b) 
{
    change(a, b);
	
    for (int i = 0; i < a.size(); ++i) 
        if (a[i] < b[i]) 
            return true;
        else if (a[i] > b[i]) 
            return false;
	
    return true;
}

bool operator >= (vi a, vi b) 
{
    change(a, b);
	
    for (int i = 0; i < a.size(); ++i) 
        if (a[i] > b[i]) 
            return true;
        else if (a[i] < b[i]) 
            return false;
	
    return true;
}

bool operator == (vi a, vi b) 
{
    change(a, b);
	
    for (int i = 0; i < a.size(); ++i) 
        if (a[i] != b[i]) return false;

    return true;
}

int main(){
    vi a, b;
    cin >> a >> b;
    cout << a << endl << b;
    return 0;
}
