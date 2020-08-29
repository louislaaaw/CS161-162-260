#include "Calculator.h"
#include <stdexcept>
#include <cmath>
using namespace std;

Calculator::Calculator() {
    num1 = 0;
    num2 = 0;
    oper = NONE;
}

void Calculator::store(double value) {
    num2 = value;
}

double Calculator::handleOperation(Calculator::opType newOperation) {
    if(newOperation == SQRT){
        num2 = sqrt(num2);
        return num2;
    }
    else if(oper != NONE){
        if(oper == SQRT){
            num2 = sqrt(num2);
            return num2;
        }
        else{
            num1 = equalsPressed();
            oper = newOperation;
            return num1;
        }
    }
    else{
        num1 = num2;
        oper = newOperation;
        return num1;
    }

}

double Calculator::equalsPressed() {
    if(oper == ADD){
        num1 += num2;
    }
    if(oper == SUBTRACT){
        num1 -= num2;
    }
    if(oper == MULTIPLY){
        num1 *= num2;
    }
    if(oper == DIVIDE){
        num1 /= num2;
    }
    return num1;
}

void Calculator::clear() {
    num1 = 0;
    num2 = 0;
    oper = NONE;
}

Calculator::opType Calculator::getOper() const{
    return oper;
}

double Calculator::getNum2() const{
    return num2;
}
