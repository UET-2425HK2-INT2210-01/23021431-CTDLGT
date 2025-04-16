#include <iostream>
#include <map>
using namespace std;
int main() {
    int so_luong;
    cin >> so_luong;
    map<int, int> dem;
    for (int i = 0; i < so_luong; i++) {
        int so;
        cin >> so;
        dem[so]++;
    }
    long long ket_qua = 0;
    for (auto const &cap : dem) {
        long long n = cap.second;
        ket_qua += (n * (n - 1)) / 2;
    }
    cout << ket_qua << endl;
    return 0;
}