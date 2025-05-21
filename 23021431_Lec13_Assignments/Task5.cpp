#include <bits/stdc++.h>
using namespace std;

int main() {
    regex pattern("[^\\n]{3}\\.[^\\n]{3}\\.[^\\n]{3}\\.[^\\n]{3}"); // 3 ký tự, dấu chấm, lặp lại 4 lần
    string s;
    while (getline(cin, s)) {
        cout << s << ": " << (regex_match(s, pattern) ? "Valid" : "Invalid") << endl;
    }
    return 0;
}
