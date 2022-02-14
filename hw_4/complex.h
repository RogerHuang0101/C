#ifndef COMPLEX
#define COMPLEX

#include <iostream>

class Complex {

    public:
    Complex(double x, double y) : re(x), im(y) {};
    Complex(double a) : re(a), im(0) {};

    double magnitude() const;

    double real();
    double imaginary();

    Complex conjugate() ;

    private:
    double re, im;
}; 

bool operator<(const Complex& a, const Complex& b);

Complex operator*(Complex& a, Complex& b);

Complex operator+(Complex& a, Complex& b);

bool operator==(Complex& a, Complex& b);

#endif