#include <iostream>
using namespace std;
struct NutNganXep {
    int gia_tri;
    NutNganXep* tiep_theo;
    NutNganXep(int gt) : gia_tri(gt), tiep_theo(nullptr) {}
};
struct NganXep {
    NutNganXep* dinh;
    NganXep() : dinh(nullptr) {}
    void day(int gia_tri) {
        NutNganXep* nut_moi = new NutNganXep(gia_tri);
        nut_moi->tiep_theo = dinh;
        dinh = nut_moi;
    }
    void lay() {
        if (!dinh) return;
        NutNganXep* tam = dinh;
        dinh = dinh->tiep_theo;
        delete tam;
    }
    void in() {
        NutNganXep* tam = dinh;
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
    NganXep nx;
    while (so_luong--) {
        string lenh;
        cin >> lenh;
        if (lenh == "push") {
            int gia_tri;
            cin >> gia_tri;
            nx.day(gia_tri);
        } else {
            nx.lay();
        }
    }
    nx.in();
    return 0;
}
