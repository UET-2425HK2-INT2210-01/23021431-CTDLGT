#include <iostream>
using namespace std;

class SapXep {
private:
    void QUICK_SORT(double mang[], int trai, int phai) { // Sắp xếp mảng bằng quicksort
        if (trai < phai) { // Nếu mảng có hơn một phần tử
            int giua = trai + (phai - trai) / 2; // Chọn pivot là phần tử giữa
            double pivot = mang[giua]; // Lưu giá trị pivot
            int i = trai, j = phai; // Khởi tạo hai chỉ số trái và phải
            
            while (i <= j) { // Lặp cho đến khi hai chỉ số gặp nhau
                while (mang[i] < pivot) i++; // Tìm phần tử lớn hơn pivot bên trái
                while (mang[j] > pivot) j--; // Tìm phần tử nhỏ hơn pivot bên phải
                if (i <= j) { // Nếu hai chỉ số chưa vượt qua nhau
                    double tam = mang[i]; // Hoán đổi hai phần tử
                    mang[i] = mang[j];
                    mang[j] = tam;
                    i++; j--; // Di chuyển chỉ số
                }
            }
            
            QUICK_SORT(mang, trai, j); // Sắp xếp mảng con trái
            QUICK_SORT(mang, i, phai); // Sắp xếp mảng con phải
        }
    }
    
public:
    void sapXepSoThuc(double mang[], int n) { // Sắp xếp mảng số thực
        if (n > 0) { // Kiểm tra mảng không rỗng
            QUICK_SORT(mang, 0, n - 1); // Gọi hàm quicksort
        }
    }
};

int main() {
    int n; // Số lượng số thực
    cout << "Nhap so luong so: "; // Yêu cầu nhập số lượng
    cin >> n; // Đọc số lượng số
    
    double danhSachSo[1000]; // Mảng lưu số thực (giới hạn tối đa 1000)
    for (int i = 0; i < n; ++i) { // Duyệt qua các số
        cin >> danhSachSo[i]; // Nhập số thực
    }
    
    SapXep boSapXep; // Khởi tạo đối tượng sắp xếp
    boSapXep.sapXepSoThuc(danhSachSo, n); // Sắp xếp mảng số
    
    for (int i = 0; i < n; ++i) { // Duyệt qua mảng đã sắp xếp
        cout << danhSachSo[i]; // In số
        if (i < n - 1) cout << " "; // Thêm khoảng trắng nếu không phải số cuối
    }
    cout << endl; // Xuống dòng
    
    return 0; 
}
