#ifndef CALCGUIDIALOG_H
#define CALCGUIDIALOG_H

#include <QDialog>
#include <QString>
#include <QLineEdit>
#include "Calculator.h"

class CalcGUIdialog : public QDialog
{
    Q_OBJECT
public:
    CalcGUIdialog(QWidget *parent = 0);


signals:

private slots:
    void ClickClear();
    void Clicknumbers1();
    void Clicknumbers2();
    void Clicknumbers3();
    void Clicknumbers4();
    void Clicknumbers5();
    void Clicknumbers6();
    void Clicknumbers7();
    void Clicknumbers8();
    void Clicknumbers9();
    void Clicknumbers0();
    void ClickPoint();
    void ClickPlus();
    void ClickMinus();
    void ClickMultiple();
    void ClickDivide();
    void ClickSqrt();
    void ClickEqual();
private:
    QLineEdit* console;
    QPushButton* MC;
    QPushButton* MR;
    QPushButton* MS;
    QPushButton* MPlus;
    QPushButton* MMinus;
    QPushButton* Back;
    QPushButton* CE;
    QPushButton* C;
    QPushButton* plusOrMinus;
    QPushButton* sqrt;
    QPushButton* seven;
    QPushButton* eight;
    QPushButton* nine;
    QPushButton* divide;
    QPushButton* percent;
    QPushButton* four;
    QPushButton* five;
    QPushButton* six;
    QPushButton* multiple;
    QPushButton* oneOverX;
    QPushButton* one;
    QPushButton* two;
    QPushButton* three;
    QPushButton* minus;
    QPushButton* zero;
    QPushButton* point;
    QPushButton* plus;
    QPushButton* equal;

    Calculator c;
};

#endif // CALCGUIDIALOG_H
