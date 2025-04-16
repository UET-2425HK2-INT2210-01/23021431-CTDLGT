#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int so_luong;
    cin >> so_luong;
    vector<int> danh_sach(so_luong);
    for (int i = 0; i < so_luong; i++) {
        cin >> danh_sach[i];
    }
    sort(danh_sach.begin(), danh_sach.end());
    for (int i = 0; i < so_luong; i++) {
        cout << danh_sach[i];
        if (i < so_luong - 1) cout << " ";
    }
    cout << endl;
    return 0;
}
