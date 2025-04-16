#include <iostream>
using namespace std;
struct NutHangDoi {
    int gia_tri;
    NutHangDoi* tiep_theo;
    NutHangDoi(int gt) : gia_tri(gt), tiep_theo(nullptr) {}
};
struct HangDoi {
    NutHangDoi *truoc, *sau;
    HangDoi() : truoc(nullptr), sau(nullptr) {}
    void them(int gia_tri) {
        NutHangDoi* nut_moi = new NutHangDoi(gia_tri);
        if (!sau) {
            truoc = sau = nut_moi;
        } else {
            sau->tiep_theo = nut_moi;
            sau = nut_moi;
        }
    }
    void xoa() {
        if (!truoc) return;
        NutHangDoi* tam = truoc;
        truoc = truoc->tiep_theo;
        delete tam;
        if (!truoc) sau = nullptr;
    }
    void in() {
        NutHangDoi* tam = truoc;
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
    HangDoi hd;
    while (so_luong--) {
        string lenh;
        cin >> lenh;
        if (lenh == "enqueue") {
            int gia_tri;
            cin >> gia_tri;
            hd.them(gia_tri);
        } else {
            hd.xoa();
        }
    }
    hd.in();
    return 0;
}
