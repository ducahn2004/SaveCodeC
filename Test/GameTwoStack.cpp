#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int twoStacks(int maxSum, vector<int> a, vector<int> b) {
    if(a.size() > b.size()) a.swap(b);
    int sumA = 0;
    stack<int> stA;
    stA.push(0);
    int result = 1;
    for (size_t i = 0; i < a.size() && sumA + a[i] <= maxSum; i++) {
        sumA += a[i];
        stA.push(a[i]);
        result++;
    }

    int tmpA = result;
    int tmpB = 0;
    // int i = 0;
    int sumB = 0;
    while (!stA.empty()) {
        while (tmpB < b.size() && sumB + b[tmpB] + sumA <= maxSum) {
            sumB += b[tmpB];
            tmpB++;
            // tmpB++;
        }
        result = max(result, tmpA + tmpB);
        sumA -= stA.top();
        stA.pop();
        tmpA--;
    }
    return result - 1;
}

int main() {
    int g;
    cin >> g;

    while (g--) {
        int m, n, sumMax;
        cin >> m >> n >> sumMax;
        vector<int> a(m);
        vector<int> b(n);

        for (int i = 0; i < m; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        cout << twoStacks(sumMax, a, b) << endl;
    }

    return 0;
}
