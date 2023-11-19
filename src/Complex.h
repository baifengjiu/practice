//
// Created by xue on 2023/11/19.
//

#ifndef PRACTICE_SRC_COMPLEX_H
#define PRACTICE_SRC_COMPLEX_H

#include <iostream>

class Complex {
public:
    explicit Complex(double r = 0.0, double imaginary = 0.0)
        : real(r)
        , imaginary(imaginary)
    {
    };

    ~Complex() = default;

    // (a+bi)-(c+di) = (a-c) + (b-d)i
    Complex operator-(const Complex &other) const {
        Complex result;
        result.real = this->real - other.real;
        result.imaginary = this->imaginary - other.imaginary;
        return result;
    };

    // (a+bi)/(c+di) = (ac+bd)/(c^2+d^2) + (bc-ad)/(c^2+d^2)i
    Complex operator/(const Complex &other) const {
        Complex result;
        double divisor = (other.real * other.real + other.imaginary * other.imaginary);
        result.real = (this->real * other.real + this->imaginary * other.imaginary) / divisor;
        result.imaginary = (this->imaginary * other.real - this->real * other.imaginary) / divisor;
        return result;
    };

    // (a+bi)+(c+di) = (a+c) + (b+d)i
    friend Complex operator+(const Complex &c1, const Complex &c2);

    // (a+bi)(c+di) = (ac-bd) + (ad+bc)i
    friend Complex operator*(const Complex &c1, const Complex &c2);

    void display() const {
        std::cout << real << " + " << imaginary << "i" << std::endl;
    }

//private:
    double real;
    double imaginary;
};

// (a+bi)+(c+di) = (a+c) + (b+d)i
Complex operator+(const Complex &c1, const Complex &c2) {
    Complex result;
    result.real = c1.real + c2.real;
    result.imaginary = c1.imaginary + c2.imaginary;
    return result;
};

// (a+bi)(c+di) = (ac-bd) + (ad+bc)i
Complex operator*(const Complex &c1, const Complex &c2){
    Complex result;
    result.real = c1.real * c2.real - c1.imaginary * c2.imaginary;
    result.imaginary = c1.real * c2.imaginary + c1.imaginary * c2.real;
    return result;
};

void testComplex() {
    Complex c1(2, 4);
    Complex c2(6, 3);
    std::cout << "Complex c1: " << c1.real << "," << c1.imaginary << "\n";
    std::cout << "Complex c2: " << c2.real << "," << c2.imaginary << "\n";

    Complex sum = c1 + c2;
    Complex difference = c1 - c2;
    Complex product = c1 * c2;
    Complex quotient = c1 / c2;

    std::cout << "Sum: ";
    sum.display();

    std::cout << "Difference: ";
    difference.display();

    std::cout << "Product: ";
    product.display();

    std::cout << "Quotient: ";
    quotient.display();
}

#endif//PRACTICE_SRC_COMPLEX_H