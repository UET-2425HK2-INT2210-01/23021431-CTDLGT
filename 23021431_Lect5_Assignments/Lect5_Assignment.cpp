#include <iostream>
using namespace std;

const int KICH_THUOC_NODE=1000;

struct NutCay {
    int duLieu; // Lưu giá trị của nút
    NutCay* conDau; // Con đầu tiên
    NutCay* anhEmKeTiep; // Anh chị em tiếp theo
    
    NutCay(int giaTri): duLieu(giaTri), conDau(nullptr), anhEmKeTiep(nullptr) {} // Khởi tạo nút
};

class Cay {
public:
    NutCay* goc; // Nút gốc của cây
    NutCay* danhSachNut[KICH_THUOC_NODE]; // Mảng lưu các nút
    bool laCon[KICH_THUOC_NODE]; // Mảng kiểm tra nút con
    
    Cay(): goc(nullptr) { // Khởi tạo cây
        for (int i = 0; i < KICH_THUOC_NODE; ++i) {
            danhSachNut[i] = nullptr; // Gán null cho mảng nút
            laCon[i] = false; // Gán false cho mảng nút con
        }
    }
    
    void capNhatGoc() { // Cập nhật nút gốc
        for (int i = 0; i < KICH_THUOC_NODE; ++i) {
            if (danhSachNut[i] != nullptr && !laCon[i]) {
                goc = danhSachNut[i]; // Gán nút gốc nếu không phải nút con
                return;
            }
        }
    }

    void themCon(int cha, int con) { // Thêm nút con vào nút cha
        if (!danhSachNut[cha]) danhSachNut[cha] = new NutCay(cha); // Tạo nút cha nếu chưa tồn tại
        if (!danhSachNut[con]) danhSachNut[con] = new NutCay(con); // Tạo nút con nếu chưa tồn tại

        NutCay* nutCha = danhSachNut[cha]; // Lấy nút cha
        NutCay* nutCon = danhSachNut[con]; // Lấy nút con

        if (!nutCha->conDau) { // Nếu chưa có con đầu
            nutCha->conDau = nutCon; // Gán nút con làm con đầu
        } else {
            NutCay* tam = nutCha->conDau; // Bắt đầu từ con đầu
            while (tam->anhEmKeTiep) { // Tìm đến anh em cuối cùng
                tam = tam->anhEmKeTiep;
            }
            tam->anhEmKeTiep = nutCon; // Thêm nút con vào cuối danh sách anh em
        }
        laCon[con] = true; // Đánh dấu nút con
        capNhatGoc(); // Cập nhật lại gốc
    }
    
    int tinhChieuCao(NutCay* nut) { // Tính chiều cao của cây
        if (!nut) return 0; // Nếu nút rỗng, trả về 0
        
        int chieuCaoLonNhat = 0; // Khởi tạo chiều cao lớn nhất
        NutCay* con = nut->conDau; // Lấy con đầu tiên
        while (con) { // Duyệt qua các con
            int cao = tinhChieuCao(con); // Tính chiều cao của cây con
            chieuCaoLonNhat = max(chieuCaoLonNhat, cao); // Cập nhật chiều cao lớn nhất
            con = con->anhEmKeTiep; // Chuyển sang anh em tiếp theo
        }
        
        return chieuCaoLonNhat + 1; // Trả về chiều cao của cây
    }
    
    int layChieuCao() { // Lấy chiều cao của cây
        return tinhChieuCao(goc) - 1; // Trừ 1 để khớp với định nghĩa chiều cao
    }

    void duyetTienTu(NutCay* nut) { // Duyệt cây theo thứ tự tiền tự
        if (!nut) return; // Nếu nút rỗng, thoát
        
        cout << nut->duLieu << " "; // In giá trị nút hiện tại
        NutCay* con = nut->conDau; // Lấy con đầu tiên
        while (con) { // Duyệt qua các con
            duyetTienTu(con); // Duyệt đệ quy cây con
            con = con->anhEmKeTiep; // Chuyển sang anh em tiếp theo
        }
    }

    void inTienTu() { // In thứ tự duyệt tiền tự
        duyetTienTu(goc); // Gọi hàm duyệt từ gốc
        cout << endl; 
    }

    void duyetHauTu(NutCay* nut) { // Duyệt cây theo thứ tự hậu tự
        if (!nut) return; // Nếu nút rỗng, thoát
        
        NutCay* con = nut->conDau; // Lấy con đầu tiên
        while (con) { // Duyệt qua các con
            duyetHauTu(con); // Duyệt đệ quy cây con
            con = con->anhEmKeTiep; // Chuyển sang anh em tiếp theo
        }
        cout << nut->duLieu << " "; // In giá trị nút hiện tại
    }

    void inHauTu() { // In thứ tự duyệt hậu tự
        duyetHauTu(goc); // Gọi hàm duyệt từ gốc
        cout << endl; // Xuống dòng
    }

    bool kiemTraCayNhiPhan(NutCay* nut) { // Kiểm tra cây nhị phân
        if (!nut) return true; // Nếu nút rỗng, là cây nhị phân
        
        NutCay* con = nut->conDau; // Lấy con đầu tiên
        int soCon = 0; // Đếm số con
        
        while (con) { // Duyệt qua các con
            soCon++; // Tăng số lượng con
            if (soCon > 2) return false; // Nếu có hơn 2 con, không phải cây nhị phân
            if (!kiemTraCayNhiPhan(con)) return false; // Kiểm tra cây con
            con = con->anhEmKeTiep; // Chuyển sang anh em tiếp theo
        }
        return true; // Nếu không vi phạm, là cây nhị phân
    }
    
    bool laCayNhiPhan() { // Kiểm tra cây có phải nhị phân
        return kiemTraCayNhiPhan(goc); // Gọi hàm kiểm tra từ gốc
    }
    
    void duyetTrungTu(NutCay* nut) { // Duyệt cây theo thứ tự trung tự
        if (!nut) return; // Nếu nút rỗng, thoát
        
        NutCay* conDau = nut->conDau; // Lấy con đầu tiên
        if (conDau) duyetTrungTu(conDau); // Duyệt cây con trái
        
        cout << nut->duLieu << " "; // In giá trị nút hiện tại
        
        if (conDau && conDau->anhEmKeTiep) { // Nếu có con thứ hai
            duyetTrungTu(conDau->anhEmKeTiep); // Duyệt cây con phải
        }
    }
    
    void inTrungTu() { // In thứ tự duyệt trung tự
        if (laCayNhiPhan()) { // Nếu là cây nhị phân
            duyetTrungTu(goc); // Gọi hàm duyệt từ gốc
            cout << endl; // Xuống dòng
        } else {
            cout << "NOT BINARY TREE" << endl; // In thông báo nếu không phải cây nhị phân
        }
    }
};

int main() {
    int soNut, soCanh; // Số nút và số cạnh
    cin >> soNut >> soCanh; // Nhập số nút và cạnh
    
    Cay cayCuaToi; // Khởi tạo cây
    
    for (int i = 0; i < soCanh; ++i) { // Đọc các cạnh
        int cha, con; // Nút cha và nút con
        cin >> cha >> con; // Nhập cha và con
        cayCuaToi.themCon(cha, con); // Thêm cạnh vào cây
    }
    
    cout << cayCuaToi.layChieuCao() << endl; // In chiều cao cây
    cayCuaToi.inTienTu(); // In thứ tự tiền tự
    cayCuaToi.inHauTu(); // In thứ tự hậu tự
    cayCuaToi.inTrungTu(); // In thứ tự trung tự
    
    return 0; 
}
