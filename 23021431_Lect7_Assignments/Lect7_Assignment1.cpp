#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class SapXep {
private:
    void GHEP_MANG(vector<double>& mang, int trai, int giua, int phai) { // Gộp hai mảng con đã sắp xếp
        vector<double> tamTrai(mang.begin() + trai, mang.begin() + giua + 1); // Tạo mảng tạm cho nửa trái
        vector<double> tamPhai(mang.begin() + giua + 1, mang.begin() + phai + 1); // Tạo mảng tạm cho nửa phải
        
        int i = 0, j = 0, k = trai; // Khởi tạo chỉ số cho mảng tạm và mảng chính
        while (i < tamTrai.size() && j < tamPhai.size()) { // So sánh và gộp
            if (tamTrai[i] <= tamPhai[j]) { // Nếu phần tử trái nhỏ hơn hoặc bằng
                mang[k++] = tamTrai[i++]; // Gán phần tử trái vào mảng chính
            } else { // Nếu phần tử phải nhỏ hơn
                mang[k++] = tamPhai[j++]; // Gán phần tử phải vào mảng chính
            }
        }
        
        while (i < tamTrai.size()) { // Gộp các phần tử còn lại của mảng trái
            mang[k++] = tamTrai[i++];
        }
        while (j < tamPhai.size()) { // Gộp các phần tử còn lại của mảng phải
            mang[k++] = tamPhai[j++];
        }
    }
    
    void SAP_XEP_GHEP(vector<double>& mang, int trai, int phai) { // Sắp xếp mảng bằng merge sort
        if (trai < phai) { // Nếu mảng có hơn một phần tử
            int giua = trai + (phai - trai) / 2; // Tính chỉ số giữa
            SAP_XEP_GHEP(mang, trai, giua); // Sắp xếp nửa trái
            SAP_XEP_GHEP(mang, giua + 1, phai); // Sắp xếp nửa phải
            GHEP_MANG(mang, trai, giua, phai); // Gộp hai nửa
        }
    }
    
public:
    void sapXepSoThuc(vector<double>& mang) { // Sắp xếp mảng số thực
        if (!mang.empty()) { // Kiểm tra mảng không rỗng
            SAP_XEP_GHEP(mang, 0, mang.size() - 1); // Gọi hàm merge sort
        }
    }
};

int main() {
    ifstream tepVao("numbers.txt"); // Mở file đầu vào
    vector<double> danhSachSo; // Danh sách lưu số thực
    double so; // Biến tạm để đọc số
    
    while (tepVao >> so) { // Đọc từng số từ file
        danhSachSo.push_back(so); // Thêm số vào danh sách
    }
    tepVao.close(); // Đóng file đầu vào
    
    SapXep boSapXep; // Khởi tạo đối tượng sắp xếp
    boSapXep.sapXepSoThuc(danhSachSo); // Sắp xếp danh sách số
    
    ofstream tepRa("numbers.sorted"); // Mở file đầu ra
    for (size_t i = 0; i < danhSachSo.size(); ++i) { // Duyệt qua danh sách số
        tepRa << danhSachSo[i]; // Ghi số vào file
        if (i < danhSachSo.size() - 1) tepRa << " "; // Thêm khoảng trắng nếu không phải số cuối
    }
    tepRa.close(); // Đóng file đầu ra
    
    return 0; 
}
