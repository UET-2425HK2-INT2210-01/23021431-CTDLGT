#include <iostream>
using namespace std;

class HoanVi {
private:
    void LIET_KE_HOAN_VI(int ketQua[], int daDung[], int n, int viTri) { // Liệt kê hoán vị
        if (viTri == n) { // Nếu đã xây dựng đủ độ dài
            for (int i = 0; i < n; ++i) cout << ketQua[i]; // In hoán vị
            cout << endl; 
            return;
        }
        
        for (int i = 1; i <= n; ++i) { // Duyệt qua các số từ 1 đến n
            if (!daDung[i]) { // Nếu số i chưa được dùng
                daDung[i] = 1; // Đánh dấu số i đã dùng
                ketQua[viTri] = i; // Gán số i vào vị trí hiện tại
                LIET_KE_HOAN_VI(ketQua, daDung, n, viTri + 1); // Gọi đệ quy cho vị trí tiếp theo
                daDung[i] = 0; // Bỏ đánh dấu để thử số khác
            }
        }
    }
    
public:
    void inHoanVi(int n) { // In tất cả hoán vị độ dài n
        int ketQua[10]; // Mảng lưu kết quả hoán vị (giới hạn tối đa 10)
        int daDung[11] = {0}; // Mảng đánh dấu số đã dùng (khởi tạo 0)
        LIET_KE_HOAN_VI(ketQua, daDung, n, 0); // Bắt đầu liệt kê từ vị trí 0
    }
};

int main() {
    int n; // Độ dài hoán vị
    cin >> n; // Nhập độ dài từ bàn phím
    
    HoanVi boLietKe; // Khởi tạo đối tượng liệt kê
    boLietKe.inHoanVi(n); // In tất cả hoán vị
    
    return 0;
}
