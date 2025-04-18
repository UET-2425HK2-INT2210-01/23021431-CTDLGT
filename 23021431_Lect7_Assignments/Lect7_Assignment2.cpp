#include <iostream>
using namespace std;

class HinhChuNhat {
private:
    int TIM_TONG_LON_NHAT(int mang[], int n, int& batDau, int& ketThuc) { // Tìm dãy con có tổng lớn nhất
        int tongMax = mang[0], tongHienTai = 0; // Khởi tạo tổng lớn nhất và tổng hiện tại
        int tamBatDau = 0; // Vị trí bắt đầu tạm thời
        batDau = 0; ketThuc = 0; // Khởi tạo vị trí bắt đầu và kết thúc
        
        for (int i = 0; i < n; ++i) { // Duyệt qua mảng
            if (tongHienTai < 0) { // Nếu tổng hiện tại âm
                tongHienTai = mang[i]; // Bắt đầu dãy mới
                tamBatDau = i; // Cập nhật vị trí bắt đầu
            } else { // Nếu tổng hiện tại không âm
                tongHienTai += mang[i]; // Cộng thêm phần tử hiện tại
            }
            
            if (tongHienTai > tongMax) { // Nếu tổng hiện tại lớn hơn tổng lớn nhất
                tongMax = tongHienTai; // Cập nhật tổng lớn nhất
                batDau = tamBatDau; // Cập nhật vị trí bắt đầu
                ketThuc = i; // Cập nhật vị trí kết thúc
            }
        }
        return tongMax; // Trả về tổng lớn nhất
    }
    
public:
    void timHinhChuNhat(int maTran[][100], int m, int n, int& hang1, int& cot1, int& hang2, int& cot2, int& tong) { // Tìm hình chữ nhật có tổng lớn nhất
        int tongMax = maTran[0][0]; // Khởi tạo tổng lớn nhất
        hang1 = cot1 = hang2 = cot2 = 1; // Khởi tạo tọa độ
        
        for (int trai = 0; trai < n; ++trai) { // Duyệt qua cột trái
            int tongTam[100] = {0}; // Mảng tạm lưu tổng cột
            for (int phai = trai; phai < n; ++phai) { // Duyệt qua cột phải
                for (int i = 0; i < m; ++i) { // Cộng dồn giá trị từ cột trái đến cột phải
                    tongTam[i] += maTran[i][phai];
                }
                
                int batDau, ketThuc; // Vị trí bắt đầu và kết thúc của dãy
                int tongHienTai = TIM_TONG_LON_NHAT(tongTam, m, batDau, ketThuc); // Tìm tổng lớn nhất của dãy
                
                if (tongHienTai > tongMax) { // Nếu tổng hiện tại lớn hơn tổng lớn nhất
                    tongMax = tongHienTai; // Cập nhật tổng lớn nhất
                    hang1 = batDau + 1; // Cập nhật hàng bắt đầu
                    hang2 = ketThuc + 1; // Cập nhật hàng kết thúc
                    cot1 = trai + 1; // Cập nhật cột bắt đầu
                    cot2 = phai + 1; // Cập nhật cột kết thúc
                    tong = tongMax; // Lưu tổng lớn nhất
                }
            }
        }
    }
};

int main() {
    int m, n; // Số hàng và cột
    cout << "Nhap m n: "; // Yêu cầu nhập số hàng và cột
    cin >> m >> n; // Đọc số hàng và cột
    
    int maTran[100][100]; // Khởi tạo ma trận (giới hạn tối đa 100x100)
    for (int i = 0; i < m; ++i) { // Duyệt qua các hàng
        for (int j = 0; j < n; ++j) { // Duyệt qua các cột
            cin >> maTran[i][j]; // Nhập giá trị ma trận
        }
    }
    
    int hang1, cot1, hang2, cot2, tong; // Biến lưu kết quả
    HinhChuNhat boTimKiem; // Khởi tạo đối tượng tìm kiếm
    boTimKiem.timHinhChuNhat(maTran, m, n, hang1, cot1, hang2, cot2, tong); // Tìm hình chữ nhật
    
    cout << hang1 << " " << cot1 << " " << hang2 << " " << cot2 << " " << tong << endl; // In kết quả
    
    return 0;
}
