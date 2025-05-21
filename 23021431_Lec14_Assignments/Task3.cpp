#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> functions = {
        "4nlogn + 2n", "2^10", "2^logn",
        "3n + 100logn", "4n", "2^n",
        "n^2 + 10n", "n^3", "nlogn"
    };

    // Sắp xếp theo Big O
    vector<string> order = {
        "2^10",          // O(1)
        "2^logn",       // O(log n) vì 2^log(n) = n
        "3n + 100logn", // O(n)
        "4n",           // O(n)
        "nlogn",        // O(n log n)
        "4nlogn + 2n",  // O(n log n)
        "n^2 + 10n",    // O(n^2)
        "n^3",          // O(n^3)
        "2^n"           // O(2^n)
    };

    for (const auto& f : order) {
        cout << f << endl; // In thứ tự
    }

    return 0;
}
