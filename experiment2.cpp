#include <iostream>
using namespace std;
class complexNumber {
    float real, imaginary;
    public :
        complexNumber(float real, float imaginary) {
            this -> real = real;
            this -> imaginary = imaginary;
        }
        complexNumber operator+(const complexNumber b) {
            float real = this -> real + b.real;
            float imaginary = this -> imaginary + b.imaginary;
            return complexNumber(real, imaginary);
        }
        float getReal() {
            return this -> real;
        }
        float getImaginary() {
            return this -> imaginary;
        }
};

int main () {
    ios_base::sync_with_stdio(0);
    float realPart, imaginaryPart;
    cout << "Enter real part of A : ";
    cin >> realPart;
    cout << "Enter imaginary part of A : ";
    cin >> imaginaryPart;
    complexNumber A(realPart, imaginaryPart);
    cout << "Enter real part of B : ";
    cin >> realPart;
    cout << "Enter imaginary part of B : ";
    cin >> imaginaryPart;
    complexNumber B(realPart, imaginaryPart);
    complexNumber C = A + B;
    cout << "Real : " << C.getReal() << "\n" ;
    cout << "Imaginary : " << C.getImaginary() << "\n" ;
}
