#include <bits/stdc++.h>
using namespace std;

int main() {
    regex pattern("\\(?\\d{3}\\)?[-. ]?\\d{3}[-. ]?\\d{4}"); // Biểu thức chính quy
    string s;
    while (getline(cin, s)) {
        cout << s << ": " << (regex_match(s, pattern) ? "Valid" : "Invalid") << endl;
    }
    return 0;
}
