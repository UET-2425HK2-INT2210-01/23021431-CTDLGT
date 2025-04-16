#include <iostream>
#include <string>
using namespace std;
int main() {
    string cau;
    getline(cin, cau);
    string ket_qua = "";
    for (int i = cau.length() - 1; i >= 0; i--) {
        ket_qua += cau[i];
    }
    cout << ket_qua << endl;
    return 0;
}