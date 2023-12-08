#include <bits/stdc++.h>

#define FOR(i, L, R) for (int i = L; i <= R; i++)
#define FORD(i, R, L) for (int i = R; i >= L; i--)

using namespace std;

const int MOD = 1e9;
typedef long long ll;

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


int lilysHomework(vector<int> arr) {
    vector<pair<int,int>> parr1;
    vector<pair<int,int>> parr2;
    for (long i = 0; i < arr.size(); i++)
        parr1.push_back({arr[i],i});    
    for (long i = 0; i < arr.size(); i++)
        parr2.push_back({arr[i],i});
    sort(parr1.begin(),parr1.end());
    sort(parr2.rbegin(),parr2.rend());
    int counta = 0; int countd = 0;  
    for (long i = 0; i < parr1.size(); i++) {
        while(i!=parr1[i].second){
            swap(parr1[i],parr1[parr1[i].second]);
            counta++;
        }
    }
    for (long i = 0; i < parr2.size(); i++) {
        while(i != parr2[i].second){
            swap(parr2[i],parr2[parr2[i].second]);
            countd++;
        }    
    }
    int result = 0;
    if (counta < countd) {
        result = counta;
    }
    else {
        result = countd;
    }
    return result;
}

int main() {
    int a, b, n;
    cin >> a >> b >> n;
    BigNumber s0, s1;
    s0.init(a);
    s1.init(b);

    while (--n >= 2) {
        BigNumber tmp = s1;
        s1 = add(multiply(s1, s1), s0);
        s0 = tmp;
    }

    s1.write();
    return 0;
}
