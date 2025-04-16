#include <iostream>
using namespace std;

class SoNhiPhan {
private:
    void LIET_KE_NHI_PHAN(char mang[], int n, int viTri) { // Liệt kê số nhị phân độ dài n
        if (viTri == n) { // Nếu đã xây dựng đủ độ dài
            for (int i = 0; i < n; ++i) cout << mang[i]; // In chuỗi nhị phân
            cout << endl; // Xuống dòng
            return;
        }
        
        mang[viTri] = '0'; // Gán bit 0 tại vị trí hiện tại
        LIET_KE_NHI_PHAN(mang, n, viTri + 1); // Gọi đệ quy cho bit tiếp theo
        
        mang[viTri] = '1'; // Gán bit 1 tại vị trí hiện tại
        LIET_KE_NHI_PHAN(mang, n, viTri + 1); // Gọi đệ quy cho bit tiếp theo
    }
    
public:
    void inSoNhiPhan(int n) { // In tất cả số nhị phân độ dài n
        char mang[20]; // Mảng lưu chuỗi nhị phân (giới hạn tối đa 20)
        LIET_KE_NHI_PHAN(mang, n, 0); // Bắt đầu liệt kê từ vị trí 0
    }
};

int main() {
    int n; // Độ dài số nhị phân
    cin >> n; // Nhập độ dài từ bàn phím
    
    SoNhiPhan boLietKe; // Khởi tạo đối tượng liệt kê
    boLietKe.inSoNhiPhan(n); // In tất cả số nhị phân
    
    return 0; 
}
