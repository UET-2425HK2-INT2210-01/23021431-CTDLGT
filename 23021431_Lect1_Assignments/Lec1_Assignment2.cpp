#include <iostream>
#include <iomanip>
using namespace std;
struct Diem {
    double hoanh_do, tung_do;
};
struct DuongThang {
    Diem diem_dau, diem_cuoi;
};
Diem tim_giao_diem(DuongThang dt1, DuongThang dt2) {
    double a1 = dt1.diem_cuoi.tung_do - dt1.diem_dau.tung_do;
    double b1 = dt1.diem_dau.hoanh_do - dt1.diem_cuoi.hoanh_do;
    double c1 = a1 * dt1.diem_dau.hoanh_do + b1 * dt1.diem_dau.tung_do;
    double a2 = dt2.diem_cuoi.tung_do - dt2.diem_dau.tung_do;
    double b2 = dt2.diem_dau.hoanh_do - dt2.diem_cuoi.hoanh_do;
    double c2 = a2 * dt2.diem_dau.hoanh_do + b2 * dt2.diem_dau.tung_do;
    double det = a1 * b2 - a2 * b1;
    Diem ket_qua;
    if (det == 0) {
        if (c1 == c2) cout << "MANY" << endl;
        else cout << "NO" << endl;
        ket_qua.hoanh_do = ket_qua.tung_do = -1;
        return ket_qua;
    }
    ket_qua.hoanh_do = (b2 * c1 - b1 * c2) / det;
    ket_qua.tung_do = (a1 * c2 - a2 * c1) / det;
    return ket_qua;
}
int main() {
    Diem diem_a, diem_b, diem_c, diem_d;
    cin >> diem_a.hoanh_do >> diem_a.tung_do;
    cin >> diem_b.hoanh_do >> diem_b.tung_do;
    cin >> diem_c.hoanh_do >> diem_c.tung_do;
    cin >> diem_d.hoanh_do >> diem_d.tung_do;
    DuongThang ab = {diem_a, diem_b};
    DuongThang cd = {diem_c, diem_d};
    Diem giao_diem = tim_giao_diem(ab, cd);
    if (giao_diem.hoanh_do != -1) {
        cout << fixed << setprecision(2) << giao_diem.hoanh_do << " " << giao_diem.tung_do << endl;
    }
    return 0;
}
