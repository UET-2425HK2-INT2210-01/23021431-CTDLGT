#include <iostream>
using namespace std;
int uoc_chung_lon_nhat(int so_m, int so_n) {
    while (so_n != 0) {
        int tam = so_m % so_n;
        so_m = so_n;
        so_n = tam;
    }
    return so_m;
}
int main() {
    int so_m, so_n;
    cin >> so_m >> so_n;
    cout << uoc_chung_lon_nhat(so_m, so_n) << endl;
    return 0;
}
