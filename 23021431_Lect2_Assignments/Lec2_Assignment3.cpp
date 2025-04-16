#include <iostream>
using namespace std;
struct NutHaiChieu {
    int gia_tri;
    NutHaiChieu *truoc, *sau;
    NutHaiChieu(int gt) : gia_tri(gt), truoc(nullptr), sau(nullptr) {}
};
struct DanhSachHaiChieu {
    NutHaiChieu *dau, *cuoi;
    DanhSachHaiChieu() : dau(nullptr), cuoi(nullptr) {}
    void them(int gia_tri) {
        NutHaiChieu* nut_moi = new NutHaiChieu(gia_tri);
        if (!dau) {
            dau = cuoi = nut_moi;
        } else {
            cuoi->sau = nut_moi;
            nut_moi->truoc = cuoi;
            cuoi = nut_moi;
        }
    }
    int dem_bo_ba() {
        int ket_qua = 0;
        NutHaiChieu* tam = dau;
        while (tam && tam->truoc && tam->sau) {
            if (tam->truoc->gia_tri + tam->gia_tri + tam->sau->gia_tri == 0) ket_qua++;
            tam = tam->sau;
        }
        return ket_qua;
    }
};
int main() {
    int so_luong;
    cin >> so_luong;
    DanhSachHaiChieu ds;
    for (int i = 0; i < so_luong; i++) {
        int gia_tri;
        cin >> gia_tri;
        ds.them(gia_tri);
    }
    cout << ds.dem_bo_ba() << endl;
    return 0;
}
