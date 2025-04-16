#include <iostream>
using namespace std;
struct Nut {
    int gia_tri;
    Nut* tiep_theo;
    Nut(int gt) : gia_tri(gt), tiep_theo(nullptr) {}
};
struct DanhSachLienKet {
    Nut* dau;
    int do_dai;
    DanhSachLienKet() : dau(nullptr), do_dai(0) {}
    void chen(int vi_tri, int gia_tri) {
        Nut* nut_moi = new Nut(gia_tri);
        if (vi_tri == 0) {
            nut_moi->tiep_theo = dau;
            dau = nut_moi;
        } else {
            Nut* tam = dau;
            for (int i = 0; i < vi_tri - 1 && tam; i++) tam = tam->tiep_theo;
            if (tam) {
                nut_moi->tiep_theo = tam->tiep_theo;
                tam->tiep_theo = nut_moi;
            }
        }
        do_dai++;
    }
    void xoa(int vi_tri) {
        if (!dau) return;
        Nut* tam = dau;
        if (vi_tri == 0) {
            dau = dau->tiep_theo;
            delete tam;
        } else {
            for (int i = 0; i < vi_tri - 1 && tam; i++) tam = tam->tiep_theo;
            if (tam && tam->tiep_theo) {
                Nut* xoa_nut = tam->tiep_theo;
                tam->tiep_theo = xoa_nut->tiep_theo;
                delete xoa_nut;
            }
        }
        do_dai--;
    }
    void in() {
        Nut* tam = dau;
        while (tam) {
            cout << tam->gia_tri;
            tam = tam->tiep_theo;
            if (tam) cout << " ";
        }
        cout << endl;
    }
};
int main() {
    int so_luong;
    cin >> so_luong;
    DanhSachLienKet ds;
    while (so_luong--) {
        string lenh;
        cin >> lenh;
        if (lenh == "insert") {
            int vi_tri, gia_tri;
            cin >> vi_tri >> gia_tri;
            ds.chen(vi_tri, gia_tri);
        } else {
            int vi_tri;
            cin >> vi_tri;
            ds.xoa(vi_tri);
        }
    }
    ds.in();
    return 0;
}
