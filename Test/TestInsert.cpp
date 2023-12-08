#include <iostream>
#include <algorithm>

using namespace std;

string multiplyStrings(string num) {
    int n = num.length();
    string result(2 * n, '0'); // Khởi tạo kết quả với độ dài là 2n và giá trị mặc định là '0'

    for (int i = n - 1; i >= 0; i--) {
        int carry = 0;
        int digit = num[i] - '0';

        for (int j = n - 1; j >= 0 || carry > 0; j--) {
            int product = ((result[j + i + 1] - '0') + carry + (digit * (j >= 0 ? (num[j] - '0') : 0)));
            result[j + i + 1] = (product % 10) + '0';
            carry = product / 10;
        }
    }

    // Loại bỏ các số 0 không cần thiết ở đầu kết quả
    result.erase(0, min(result.find_first_not_of('0'), result.size() - 1));

    return result;
}

int main() {
    string num;
    cin >> num;

    string result = multiplyStrings(num);
     cout << result;

    return 0;
}
