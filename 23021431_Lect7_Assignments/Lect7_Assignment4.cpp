#include <iostream>
#include <string>
using namespace std;

class SoNhiPhan {
private:
    void LIET_KE_NHI_PHAN(string chuoi, int n, int viTri) { // Liệt kê số nhị phân độ dài n
        if (viTri == n) { // Nếu đã xây dựng đủ độ dài
            cout << chuoi << endl; // In chuỗi nhị phân
            return;
        }
        
        chuoi[viTri] = '0'; // Gán bit 0 tại vị trí hiện tại
        LIET_KE_NHI_PHAN(chuoi, n, viTri + 1); // Gọi đệ quy cho bit tiếp theo
        
        chuoi[viTri] = '1'; // Gán bit 1 tại vị trí hiện tại
        LIET_KE_NHI_PHAN(chuoi, n, viTri + 1); // Gọi đệ quy cho bit tiếp theo
    }
    
public:
    void inSoNhiPhan(int n) { // In tất cả số nhị phân độ dài n
        string chuoi(n, '0'); // Khởi tạo chuỗi với n ký tự '0'
        LIET_KE_NHI_PHAN(chuoi, n, 0); // Bắt đầu liệt kê từ vị trí 0
    }
};

int main() {
    int n; // Độ dài số nhị phân
    cin >> n; // Nhập độ dài từ bàn phím
    
    SoNhiPhan boLietKe; // Khởi tạo đối tượng liệt kê
    boLietKe.inSoNhiPhan(n); // In tất cả số nhị phân
    
    return 0; // Kết thúc chương trình
}
