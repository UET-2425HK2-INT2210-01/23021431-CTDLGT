#include <bits/stdc++.h>
using namespace std;

class Complex {
private:
    double real; // Phần thực
    double imag; // Phần ảo
public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {} // Constructor

    // Cộng số phức
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Trừ số phức
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    // Nhân số phức
    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }

    // In số phức
    void print() const {
        cout << real << (imag >= 0 ? "+" : "") << imag << "i" << endl;
    }
};

int main() {
    Complex a(3, 4), b(1, -2); // Ví dụ
    (a + b).print(); // Cộng
    (a - b).print(); // Trừ
    (a * b).print(); // Nhân
    return 0;
}
