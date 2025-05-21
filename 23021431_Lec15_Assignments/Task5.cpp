#include <bits/stdc++.h>
using namespace std;

void generateBinary(int n, int ones, int zeros, string current, vector<string>& result) {
    if (current.size() == n) {
        if (ones <= zeros) {
            result.push_back(current); // Thêm chuỗi hợp lệ
        }
        return;
    }
    // Thêm 0
    generateBinary(n, ones, zeros + 1, current + "0", result);
    // Thêm 1 nếu số 1 không vượt quá số 0
    if (ones < zeros) {
        generateBinary(n, ones + 1, zeros, current + "1", result);
    }
}

int main() {
    int n;
    cin >> n; // Nhập n
    vector<string> result;
    generateBinary(n, 0, 0, "", result); // Sinh số nhị phân

    for (const auto& s : result) {
        cout << s << endl; // In kết quả
    }

    return 0;
}
