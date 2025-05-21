#include <bits/stdc++.h>
using namespace std;

int main() {
    // Biểu thức chính quy
    regex pattern1("s[^>]+>"); // Khớp s theo sau là các ký tự không phải '>' và kết thúc bằng '>'
    regex pattern2("a.[bc]+"); // Khớp a, một ký tự bất kỳ, theo sau là chuỗi các ký tự b hoặc c

    vector<string> strings = {"abc", "abbbbbbb", "azc", "abcbcbcbc", "ac", "azccbbbbcbccc"};

    // Kiểm tra pattern1
    cout << "For pattern /s[^>]+>:" << endl;
    for (const auto& s : strings) {
        cout << s << ": " << (regex_match(s, pattern1) ? "Match" : "No Match") << endl;
    }

    // Kiểm tra pattern2
    cout << "\nFor pattern /a.[bc]+:" << endl;
    for (const auto& s : strings) {
        cout << s << ": " << (regex_match(s, pattern2) ? "Match" : "No Match") << endl;
    }

    return 0;
}
