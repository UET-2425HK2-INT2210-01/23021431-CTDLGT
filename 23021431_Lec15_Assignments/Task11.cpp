#include <bits/stdc++.h>
using namespace std;
//Giống bài 6 lec 13 :vv

int main() {
    regex pattern("([0-9a-zA-Z]+[-_ ]?[0-9a-zA-Z]+)*");
    string s;
    while (getline(cin, s)) {
        cout << s << ": " << (regex_match(s, pattern) ? "Valid" : "Invalid") << endl;
    }
    return 0;
}
