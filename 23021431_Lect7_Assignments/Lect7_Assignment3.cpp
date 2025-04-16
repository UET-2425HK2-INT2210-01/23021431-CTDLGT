#include <iostream>
using namespace std;

class UocChung {
private:
    int TIM_UCLN(int a, int b) { // Tìm ước chung lớn nhất bằng đệ quy
        a = abs(a); b = abs(b); // Lấy giá trị tuyệt đối của a và b
        if (b == 0) return a; // Nếu b bằng 0, trả về a
        return TIM_UCLN(b, a % b); // Gọi đệ quy với b và a % b
    }
    
public:
    int tinhUocChung(int x, int y) { // Tính UCLN của x và y
        return TIM_UCLN(x, y); // Gọi hàm đệ quy
    }
};

int main() {
    int x, y; // Hai số đầu vào
    cin >> x >> y; // Nhập hai số từ bàn phím
    
    UocChung boTinhToan; // Khởi tạo đối tượng tính toán
    int ketQua = boTinhToan.tinhUocChung(x, y); // Tính UCLN
    cout << ketQua << endl; // In kết quả
    
    return 0; // Kết thúc chương trình
}
