#include <math.h>
#include "complex.h"

double Complex::magnitude() const {

    return sqrt(re * re + im * im);

}

double Complex::real() {
    return re;
}

double Complex::imaginary() {
    return im;
}

Complex Complex::conjugate() {

    return Complex(re, (-1) * im) ;

}

bool operator<(const Complex& a, const Complex& b) {

    return a.magnitude() < b.magnitude();

}

Complex operator*(Complex& a, Complex& b) {

    return Complex(a.real() * b.real() - a.imaginary() * b.imaginary(), a.real() * b.imaginary() + b.real() * a.imaginary() );

}

Complex operator+(Complex& a, Complex& b) {

    return Complex(a.real() + b.real(), a.imaginary() + b.imaginary());

}

bool operator==(Complex& a, Complex& b) {

    return (a.real() == b.real()) || (a.imaginary() == b.imaginary());

}
