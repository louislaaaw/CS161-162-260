/**
 * @brief Assignment 5
 * @author (Louis)YunHo Law
 **/
#ifndef MYCOMPLEX_H
#define MYCOMPLEX_H

#include <iostream>
#include <cmath>

using namespace std;

class MyComplex {
public:
    MyComplex();
    MyComplex(double realValue);
    MyComplex(double realValue, double imaginaryNumber);
    MyComplex operator+(const MyComplex& c1);
    MyComplex operator-(const MyComplex& c1);
    MyComplex operator*(const MyComplex& c1);
    MyComplex operator/(const MyComplex& c1);
    MyComplex& operator++();
    MyComplex& operator--();
    MyComplex operator++(int dummy);
    MyComplex operator--(int dummy);
    MyComplex& operator+=(const MyComplex& c1);
    MyComplex& operator*=(const MyComplex& c1);
    MyComplex& operator-=(const MyComplex& c1);
    MyComplex& operator/=(const MyComplex& c1);
    MyComplex operator-();
    bool operator==(const MyComplex& other);
    bool operator!=(const MyComplex& other);
    friend ostream& operator<<(ostream& stream, const MyComplex& c1);
    friend istream& operator>>(istream& stream, MyComplex& c1);
    double getRealPart();
    double getComplexPart();

private:
    double real;
    double imaginary;
};

#endif // MYCOMPLEX_H
