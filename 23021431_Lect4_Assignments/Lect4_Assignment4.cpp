#include <iostream>
#include <string>
using namespace std;
const int KICH_THUOC_BANG = 11;
class DanhSachSinhVien {
private:
    struct SinhVien {
        int maSV;
        string tenSV;
        string lopSV;
        SinhVien() : maSV(-1), tenSV(""), lopSV("") {}
        SinhVien(int id, string ten, string lop) : maSV(id), tenSV(ten), lopSV(lop) {}
    };
    SinhVien bangBam[KICH_THUOC_BANG];
    int hamBam(int maSV) {
        return maSV % KICH_THUOC_BANG;
    }
public:
    DanhSachSinhVien() {
        for (int i = 0; i < KICH_THUOC_BANG; i++) {
            bangBam[i] = SinhVien();
        }
    }
    void chenSinhVien(int maSV, string tenSV, string lopSV) {
        int chiSo = hamBam(maSV);
        int chiSoBanDau = chiSo;
        while (bangBam[chiSo].maSV != -1 && bangBam[chiSo].maSV != maSV) {
            chiSo = (chiSo + 1) % KICH_THUOC_BANG;
            if (chiSo == chiSoBanDau) return;
        }
        bangBam[chiSo] = SinhVien(maSV, tenSV, lopSV);
    }
    void xoaSinhVien(int maSV) {
        int chiSo = hamBam(maSV);
        int chiSoBanDau = chiSo;
        while (bangBam[chiSo].maSV != -1) {
            if (bangBam[chiSo].maSV == maSV) {
                bangBam[chiSo] = SinhVien();
                return;
            }
            chiSo = (chiSo + 1) % KICH_THUOC_BANG;
            if (chiSo == chiSoBanDau) return;
        }
    }
    void thongTinSinhVien(int maSV) {
        int chiSo = hamBam(maSV);
        int chiSoBanDau = chiSo;
        while (bangBam[chiSo].maSV != -1) {
            if (bangBam[chiSo].maSV == maSV) {
                cout << bangBam[chiSo].tenSV << "," << bangBam[chiSo].lopSV << endl;
                return;
            }
            chiSo = (chiSo + 1) % KICH_THUOC_BANG;
            if (chiSo == chiSoBanDau) break;
        }
        cout << "NA,NA" << endl;
    }
};
int main() {
    DanhSachSinhVien quanLySV;
    string lenh;
    while (cin >> lenh) {
        if (lenh == "Insert") {
            int maSV;
            string tenSV, lopSV;
            cin >> maSV;
            cin.ignore();
            getline(cin, tenSV, ',');
            getline(cin, lopSV);
            quanLySV.chenSinhVien(maSV, tenSV, lopSV);
        } else if (lenh == "Delete") {
            int maSV;
            cin >> maSV;
            quanLySV.xoaSinhVien(maSV);
        } else if (lenh == "Infor") {
            int maSV;
            cin >> maSV;
            quanLySV.thongTinSinhVien(maSV);
        }
    }
    return 0;
}