#include <bits/stdc++.h>
using namespace std;

int main() {
    regex pattern("(very )+(fat )?(tall|ugly) man"); // Biểu thức chính quy
    vector<string> strings = {"very fat man", "fat tall man", "very very fat ugly man", "very very very tall man"};

    for (const auto& s : strings) {
        cout << s << ": " << (regex_match(s, pattern) ? "Match" : "No Match") << endl;
    }

    return 0;
}
