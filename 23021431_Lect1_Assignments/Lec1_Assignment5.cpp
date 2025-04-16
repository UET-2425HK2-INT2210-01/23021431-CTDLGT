#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    vector<double> danh_sach(5);
    for (int i = 0; i < 5; i++) {
        cin >> danh_sach[i];
    }
    double nho_nhat = *min_element(danh_sach.begin(), danh_sach.end());
    double lon_nhat = *max_element(danh_sach.begin(), danh_sach.end());
    cout << fixed << setprecision(2) << nho_nhat + lon_nhat << endl;
    return 0;
}
