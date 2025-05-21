#include <bits/stdc++.h>
using namespace std;

int main() {
    regex pattern("([0-9a-zA-Z]+[-_ ]?[0-9a-zA-Z]+)*"); // Biểu thức chính quy
    string s;
    while (getline(cin, s)) {
        cout << s << ": " << (regex_match(s, pattern) ? "Valid" : "Invalid") << endl;
    }
    return 0;
}
