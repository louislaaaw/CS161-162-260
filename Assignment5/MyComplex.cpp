/**
 * @brief Assignment 5
 * @author (Louis)YunHo Law
 **/

#include <iostream>
#include <cmath>
#include "MyComplex.h"

using namespace std;

MyComplex::MyComplex(){
    real = 0;
    imaginary = 0;
}

MyComplex::MyComplex(double realValue){
    real = realValue;
    imaginary = 0;
}

MyComplex::MyComplex(double realValue, double imaginaryNumber){
    real = realValue;
    imaginary = imaginaryNumber;
}

MyComplex MyComplex::operator+(const MyComplex& c1){
    double a = real + c1.real;
    double b = imaginary + c1.imaginary;
    return MyComplex(a,b);
}

MyComplex MyComplex::operator-(const MyComplex& c1){
    double a = real - c1.real;
    double b = imaginary - c1.imaginary;
    return MyComplex(a,b);
}

MyComplex MyComplex::operator*(const MyComplex& c1){
    double a = (real * c1.real) + ((imaginary * c1.imaginary ) * -1);
    double b = (real * c1.imaginary) + (imaginary * c1.real);
    return MyComplex(a,b);
}

MyComplex MyComplex::operator/(const MyComplex& c1){
    double denominator = c1.real * c1.real - c1.imaginary * c1.imaginary * -1;
    double a = (real * c1.real + imaginary * c1.imaginary) / denominator ;
    double b = ((real * (c1.imaginary * -1)) + (imaginary * c1.real)) / denominator ;
    return MyComplex(a,b);
}

MyComplex& MyComplex::operator++(){
    real = real + 1;
    return* this;
}

MyComplex& MyComplex::operator--(){
    real = real - 1;
    return* this;
}

MyComplex MyComplex::operator++(int dummy){
    MyComplex temp(real,imaginary);
    real = real + 1;
    dummy = dummy;
    return temp;
}

MyComplex MyComplex::operator--(int dummy){
    MyComplex temp(real,imaginary);
    real = real - 1;
    dummy = dummy;
    return temp;
}

MyComplex& MyComplex::operator+=(const MyComplex& c1){
    double a = real + c1.real;
    double b = imaginary + c1.imaginary;
    real = a;
    imaginary = b;
    return* this;
}

MyComplex& MyComplex::operator*=(const MyComplex& c1){
    double a = (real * c1.real) + ((imaginary * c1.imaginary ) * -1);
    double b = (real * c1.imaginary) + (imaginary * c1.real);
    real = a;
    imaginary = b;
    return* this;
}

MyComplex& MyComplex::operator-=(const MyComplex& c1){
    double a = real - c1.real;
    double b = imaginary - c1.imaginary;
    real = a;
    imaginary = b;
    return* this;
}

MyComplex& MyComplex::operator/=(const MyComplex& c1){
    double denominator = c1.real * c1.real - c1.imaginary * c1.imaginary * -1;
    double a = (real * c1.real + imaginary * c1.imaginary) / denominator ;
    double b = ((real * (c1.imaginary * -1)) + (imaginary * c1.real)) / denominator ;
    real = a;
    imaginary = b;
    return* this;
}

MyComplex MyComplex::operator-(){
    double a = -1 * real;
    double b = -1 * imaginary;
    return MyComplex(a,b);
}

bool MyComplex::operator==(const MyComplex& c1){
    double a = real - c1.real;
    double b = imaginary - c1.imaginary;

    return (static_cast<int>(a) == 0) && (static_cast<int>(b) == 0);
}

bool MyComplex::operator!=(const MyComplex& c1){
    double a = real - c1.real;
    double b = imaginary - c1.imaginary;

    return (static_cast<int>(a) != 0) || (static_cast<int>(b) != 0);
}

ostream& operator<<(ostream& stream, const MyComplex& c1){
    double a = c1.real;
    char sign = '+';
    double b = c1.imaginary;
    if (b < 0){
        if(sign == '+'){
            sign = '-';
        }
        b *= -1;
    }

    stream << a << " " << sign << " " << b << "i";
    return stream;
}

istream& operator>>(istream& stream, MyComplex& c1){
    stream >> c1.real;
    char sign;
    stream >> sign;
    if ((sign != '+') && (sign != '-'))
        cout << "wrong sign..." << endl;
        exit(0);
    stream >> c1.imaginary;
    char i;
    stream >> i;
    if (i == 'i')
        cout << "wrong symbol" << endl;

    return stream;
}

double MyComplex::getRealPart(){
    return real;
}

double MyComplex::getComplexPart(){
    return imaginary;
}
