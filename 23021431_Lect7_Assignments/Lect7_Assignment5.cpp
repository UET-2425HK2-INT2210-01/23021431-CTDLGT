#include <iostream>
#include <vector>
using namespace std;

class HoanVi {
private:
    void LIET_KE_HOAN_VI(vector<int>& ketQua, vector<bool>& daDung, int n, int viTri) { // Liệt kê hoán vị
        if (viTri == n) { // Nếu đã xây dựng đủ độ dài
            for (int x : ketQua) cout << x; // In hoán vị
            cout << endl; // Xuống dòng
            return;
        }
        
        for (int i = 1; i <= n; ++i) { // Duyệt qua các số từ 1 đến n
            if (!daDung[i]) { // Nếu số i chưa được dùng
                daDung[i] = true; // Đánh dấu số i đã dùng
                ketQua[viTri] = i; // Gán số i vào vị trí hiện tại
                LIET_KE_HOAN_VI(ketQua, daDung, n, viTri + 1); // Gọi đệ quy cho vị trí tiếp theo
                daDung[i] = false; // Bỏ đánh dấu để thử số khác
            }
        }
    }
    
public:
    void inHoanVi(int n) { // In tất cả hoán vị độ dài n
        vector<int> ketQua(n); // Mảng lưu kết quả hoán vị
        vector<bool> daDung(n + 1, false); // Mảng đánh dấu số đã dùng
        LIET_KE_HOAN_VI(ketQua, daDung, n, 0); // Bắt đầu liệt kê từ vị trí 0
    }
};

int main() {
    int n; // Độ dài hoán vị
    cin >> n; // Nhập độ dài từ bàn phím
    
    HoanVi boLietKe; // Khởi tạo đối tượng liệt kê
    boLietKe.inHoanVi(n); // In tất cả hoán vị
    
    return 0; // Kết thúc chương trình
}
