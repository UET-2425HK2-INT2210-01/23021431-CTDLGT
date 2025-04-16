#include <iostream>
using namespace std;

class UocChung {
private:
    int TIM_UCLN(int a, int b) { // Tìm ước chung lớn nhất bằng đệ quy
        a = a < 0 ? -a : a; // Lấy giá trị tuyệt đối của a
        b = b < 0 ? -b : b; // Lấy giá trị tuyệt đối của b
        return b == 0 ? a : TIM_UCLN(b, a % b); // Nếu b bằng 0 trả về a, ngược lại gọi đệ quy
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
    cout << boTinhToan.tinhUocChung(x, y) << endl; // In kết quả UCLN
    
    return 0; 
}
