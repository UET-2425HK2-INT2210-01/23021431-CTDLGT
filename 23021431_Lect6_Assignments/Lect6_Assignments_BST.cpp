#include <iostream>
using namespace std;

class CayNhiPhan {
private:
    struct Node {
        int giaTri; // Giá trị của node
        Node* benTrai; // Con trái
        Node* benPhai; // Con phải
        
        Node(int val): giaTri(val), benTrai(nullptr), benPhai(nullptr) {} // Khởi tạo node với giá trị và con rỗng
    };
    
    void DUYET_TRUNG_TU(Node* node) { // Duyệt cây theo thứ tự trung tự (trái, gốc, phải)
        if (node != nullptr) { // Kiểm tra node không rỗng
            DUYET_TRUNG_TU(node->benTrai); // Duyệt cây con trái
            cout << node->giaTri << " "; // In giá trị của node hiện tại
            DUYET_TRUNG_TU(node->benPhai); // Duyệt cây con phải
        }
    }
    
    Node* CHEN_NODE(Node* node, int val) { // Chèn giá trị vào cây nhị phân
        if (!node) return new Node(val); // Nếu cây rỗng, tạo node mới làm gốc
        
        if (val <= node->giaTri) { // Nếu giá trị nhỏ hơn hoặc bằng, chèn vào bên trái
            node->benTrai = CHEN_NODE(node->benTrai, val); // Gọi đệ quy để chèn vào cây con trái
        } else { // Nếu giá trị lớn hơn, chèn vào bên phải
            node->benPhai = CHEN_NODE(node->benPhai, val); // Gọi đệ quy để chèn vào cây con phải
        }
        
        return node; // Trả về node hiện tại sau khi chèn
    }
    
    Node* TIM_NHO_NHAT(Node* node) { // Tìm node có giá trị nhỏ nhất trong cây con
        Node* hienTai = node; // Lưu node hiện tại
        while (hienTai && hienTai->benTrai) { // Di chuyển đến node trái nhất
            hienTai = hienTai->benTrai; // Cập nhật node hiện tại
        }
        return hienTai; // Trả về node có giá trị nhỏ nhất
    }
    
    Node* XOA_NODE(Node* node, int val) { // Xóa node có giá trị val khỏi cây
        if (!node) return node; // Nếu node rỗng, trả về null
        
        if (val < node->giaTri) { // Nếu giá trị nhỏ hơn, tìm ở cây con trái
            node->benTrai = XOA_NODE(node->benTrai, val); // Gọi đệ quy để xóa ở cây con trái
        } else if (val > node->giaTri) { // Nếu giá trị lớn hơn, tìm ở cây con phải
            node->benPhai = XOA_NODE(node->benPhai, val); // Gọi đệ quy để xóa ở cây con phải
        } else { // Tìm thấy node cần xóa
            if (!node->benTrai && !node->benPhai) { // Trường hợp 1: Node lá (không có con)
                delete node; // Giải phóng node
                return nullptr; // Trả về null để ngắt liên kết
            } else if (!node->benTrai) { // Trường hợp 2: Chỉ có con phải
                Node* tam = node->benPhai; // Lưu con phải
                delete node; // Giải phóng node
                return tam; // Trả về con phải để nối với cha
            } else if (!node->benPhai) { // Trường hợp 2: Chỉ có con trái
                Node* tam = node->benTrai; // Lưu con trái
                delete node; // Giải phóng node
                return tam; // Trả về con trái để nối với cha
            } else { // Trường hợp 3: Có cả hai con
                Node* nhoNhat = TIM_NHO_NHAT(node->benPhai); // Tìm node nhỏ nhất ở cây con phải
                node->giaTri = nhoNhat->giaTri; // Thay giá trị node hiện tại bằng giá trị nhỏ nhất
                node->benPhai = XOA_NODE(node->benPhai, nhoNhat->giaTri); // Xóa node nhỏ nhất
            }
        }
        return node; // Trả về node hiện tại sau khi xóa
    }
    
public:
    Node* gocCay; // Node gốc của cây nhị phân
    
    CayNhiPhan(): gocCay(nullptr) {} // Khởi tạo cây với gốc rỗng
    
    void themGiaTri(int val) { // Thêm giá trị vào cây
        gocCay = CHEN_NODE(gocCay, val); // Gọi hàm chèn và cập nhật gốc
    }

    void xoaGiaTri(int val) { // Xóa giá trị khỏi cây
        gocCay = XOA_NODE(gocCay, val); // Gọi hàm xóa và cập nhật gốc
    }
    
    void inTrungTu() { // In cây theo thứ tự trung tự
        DUYET_TRUNG_TU(gocCay); // Gọi hàm duyệt từ gốc
        cout << endl; 
    }
};

int main() {
    CayNhiPhan cayCuaToi; // Khởi tạo cây nhị phân tìm kiếm
    
    // Thêm các giá trị từ danh sách: 2, 1, 10, 6, 3, 8, 7, 13, 20
    cayCuaToi.themGiaTri(2); // Thêm giá trị 2
    cayCuaToi.themGiaTri(1); // Thêm giá trị 1
    cayCuaToi.themGiaTri(10); // Thêm giá trị 10
    cayCuaToi.themGiaTri(6); // Thêm giá trị 6
    cayCuaToi.themGiaTri(3); // Thêm giá trị 3
    cayCuaToi.themGiaTri(8); // Thêm giá trị 8
    cayCuaToi.themGiaTri(7); // Thêm giá trị 7
    cayCuaToi.themGiaTri(13); // Thêm giá trị 13
    cayCuaToi.themGiaTri(20); // Thêm giá trị 20
    
    cout << "Cay sau khi tao: "; // In tiêu đề
    cayCuaToi.inTrungTu(); // In cây: 1 2 3 6 7 8 10 13 20
    
    // Thêm các giá trị: 14, 0, 35
    cayCuaToi.themGiaTri(14); // Thêm giá trị 14
    cayCuaToi.themGiaTri(0); // Thêm giá trị 0
    cayCuaToi.themGiaTri(35); // Thêm giá trị 35
    
    cout << "Cay sau khi them 14, 0, 35: "; // In tiêu đề
    cayCuaToi.inTrungTu(); // In cây: 0 1 2 3 6 7 8 10 13 14 20 35
    
    // Xóa các giá trị: 6, 13, 35
    cayCuaToi.xoaGiaTri(6); // Xóa giá trị 6
    cayCuaToi.xoaGiaTri(13); // Xóa giá trị 13
    cayCuaToi.xoaGiaTri(35); // Xóa giá trị 35
    
    cout << "Cay sau khi xoa 6, 13, 35: "; // In tiêu đề
    cayCuaToi.inTrungTu(); // In cây: 0 1 2 3 7 8 10 14 20
    
    return 0; 
}
