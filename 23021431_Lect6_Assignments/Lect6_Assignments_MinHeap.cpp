#include <iostream>
#include <vector>
using namespace std;

class VungNho {
private:
    vector<int> danhSach; // Danh sách lưu các phần tử của heap
    
    int layCha(int chiSo) { // Tính chỉ số của cha
        return (chiSo - 1) / 2; // Công thức lấy chỉ số cha
    }
    
    int layConTrai(int chiSo) { // Tính chỉ số của con trái
        return 2 * chiSo + 1; // Công thức lấy chỉ số con trái
    }
    
    int layConPhai(int chiSo) { // Tính chỉ số của con phải
        return 2 * chiSo + 2; // Công thức lấy chỉ số con phải
    }
    
    void SIFT_UP(int chiSo) { // Đẩy phần tử lên để duy trì tính chất heap
        while (chiSo > 0 && danhSach[chiSo] < danhSach[layCha(chiSo)]) { // Nếu phần tử nhỏ hơn cha
            swap(danhSach[chiSo], danhSach[layCha(chiSo)]); // Hoán đổi với cha
            chiSo = layCha(chiSo); // Cập nhật chỉ số lên cha
        }
    }
    
    void SIFT_DOWN(int chiSo) { // Đẩy phần tử xuống để duy trì tính chất heap
        int kichThuoc = danhSach.size(); // Lấy kích thước heap
        int chiSoNhoNhat = chiSo; // Giả sử phần tử hiện tại là nhỏ nhất
        
        int conTrai = layConTrai(chiSo); // Lấy chỉ số con trái
        if (conTrai < kichThuoc && danhSach[conTrai] < danhSach[chiSoNhoNhat]) { // Nếu con trái nhỏ hơn
            chiSoNhoNhat = conTrai; // Cập nhật chỉ số nhỏ nhất
        }
        
        int conPhai = layConPhai(chiSo); // Lấy chỉ số con phải
        if (conPhai < kichThuoc && danhSach[conPhai] < danhSach[chiSoNhoNhat]) { // Nếu con phải nhỏ hơn
            chiSoNhoNhat = conPhai; // Cập nhật chỉ số nhỏ nhất
        }
        
        if (chiSoNhoNhat != chiSo) { // Nếu tìm thấy phần tử nhỏ hơn
            swap(danhSach[chiSo], danhSach[chiSoNhoNhat]); // Hoán đổi với phần tử nhỏ nhất
            SIFT_DOWN(chiSoNhoNhat); // Tiếp tục đẩy xuống ở vị trí mới
        }
    }
    
    void CHEN_GIA_TRI(int val) { // Chèn giá trị vào heap
        danhSach.push_back(val); // Thêm giá trị vào cuối danh sách
        SIFT_UP(danhSach.size() - 1); // Đẩy giá trị lên để duy trì heap
    }
    
    void XOA_GIA_TRI(int val) { // Xóa giá trị khỏi heap
        int chiSo = -1; // Khởi tạo chỉ số cần xóa
        for (int i = 0; i < danhSach.size(); i++) { // Tìm giá trị trong danh sách
            if (danhSach[i] == val) { // Nếu tìm thấy giá trị
                chiSo = i; // Lưu chỉ số
                break; // Thoát vòng lặp
            }
        }
        
        if (chiSo == -1) return; // Nếu không tìm thấy giá trị, thoát
        
        danhSach[chiSo] = danhSach.back(); // Thay giá trị cần xóa bằng giá trị cuối
        danhSach.pop_back(); // Xóa phần tử cuối
        
        if (chiSo < danhSach.size()) { // Nếu chỉ số hợp lệ
            SIFT_UP(chiSo); // Đẩy lên nếu cần
            SIFT_DOWN(chiSo); // Đẩy xuống nếu cần
        }
    }
    
public:
    VungNho() {} // Khởi tạo heap rỗng
    
    void themPhanTu(int val) { // Thêm phần tử vào heap
        CHEN_GIA_TRI(val); // Gọi hàm chèn giá trị
    }
    
    void xoaPhanTu(int val) { // Xóa phần tử khỏi heap
        XOA_GIA_TRI(val); // Gọi hàm xóa giá trị
    }
    
    void inHeap() { // In toàn bộ heap
        for (int val : danhSach) { // Duyệt qua các phần tử trong danh sách
            cout << val << " "; // In giá trị
        }
        cout << endl; 
    }
};

int main() {
    VungNho heapCuaToi; // Khởi tạo heap
    
    // Thêm các giá trị từ danh sách: 2, 1, 10, 6, 3, 8, 7, 13, 20
    heapCuaToi.themPhanTu(2); // Thêm giá trị 2
    heapCuaToi.themPhanTu(1); // Thêm giá trị 1
    heapCuaToi.themPhanTu(10); // Thêm giá trị 10
    heapCuaToi.themPhanTu(6); // Thêm giá trị 6
    heapCuaToi.themPhanTu(3); // Thêm giá trị 3
    heapCuaToi.themPhanTu(8); // Thêm giá trị 8
    heapCuaToi.themPhanTu(7); // Thêm giá trị 7
    heapCuaToi.themPhanTu(13); // Thêm giá trị 13
    heapCuaToi.themPhanTu(20); // Thêm giá trị 20
    
    cout << "Heap sau khi tao: "; // In tiêu đề
    heapCuaToi.inHeap(); // In heap: 1 2 7 3 10 8 6 13 20
    
    // Thêm các giá trị: 14, 0, 35
    heapCuaToi.themPhanTu(14); // Thêm giá trị 14
    heapCuaToi.themPhanTu(0); // Thêm giá trị 0
    heapCuaToi.themPhanTu(35); // Thêm giá trị 35
    
    cout << "Heap sau khi them 14, 0, 35: "; // In tiêu đề
    heapCuaToi.inHeap(); // In heap: 0 1 7 3 2 8 6 13 20 14 10 35
    
    // Xóa các giá trị: 6, 13, 35
    heapCuaToi.xoaPhanTu(6); // Xóa giá trị 6
    heapCuaToi.xoaPhanTu(13); // Xóa giá trị 13
    heapCuaToi.xoaPhanTu(35); // Xóa giá trị 35
    
    cout << "Heap sau khi xoa 6, 13, 35: "; // In tiêu đề
    heapCuaToi.inHeap(); // In heap: 0 1 7 3 2 8 14 10 20
    
    return 0; 
}
