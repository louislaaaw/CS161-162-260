#include "Calculator.h"
#include "CalcGUIdialog.h"
#include <QDialog>
#include <QLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QString>

CalcGUIdialog::CalcGUIdialog(QWidget* parent) : QDialog(parent)
{
    console = new QLineEdit;
    MC = new QPushButton("MC");
    MR = new QPushButton("MR");
    MS = new QPushButton("MS");
    MPlus = new QPushButton("M+");
    MMinus = new QPushButton("M-");
    Back = new QPushButton("←");
    CE = new QPushButton("CE");
    C = new QPushButton("C");
    plusOrMinus = new QPushButton("±");
    sqrt = new QPushButton("√");
    seven = new QPushButton("7");
    eight = new QPushButton("8");
    nine = new QPushButton("9");
    divide = new QPushButton("/");
    percent = new QPushButton("%");
    four = new QPushButton("4");
    five = new QPushButton("5");
    six = new QPushButton("6");
    multiple = new QPushButton("*");
    oneOverX = new QPushButton("1/x");
    one = new QPushButton("1");
    two = new QPushButton("2");
    three = new QPushButton("3");
    minus = new QPushButton("-");
    zero = new QPushButton("0");
    point = new QPushButton(".");
    plus = new QPushButton("+");
    equal = new QPushButton("=");



    QHBoxLayout* layout1 = new QHBoxLayout;
    layout1->addWidget(MC);
    layout1->addWidget(MR);
    layout1->addWidget(MS);
    layout1->addWidget(MPlus);
    layout1->addWidget(MMinus);
    QHBoxLayout* layout2 = new QHBoxLayout;
    layout2->addWidget(Back);
    layout2->addWidget(CE);
    layout2->addWidget(C);
    layout2->addWidget(plusOrMinus);
    layout2->addWidget(sqrt);
    QHBoxLayout* layout3 = new QHBoxLayout;
    layout3->addWidget(seven);
    layout3->addWidget(eight);
    layout3->addWidget(nine);
    layout3->addWidget(divide);
    layout3->addWidget(percent);
    QHBoxLayout* layout4 = new QHBoxLayout;
    layout4->addWidget(four);
    layout4->addWidget(five);
    layout4->addWidget(six);
    layout4->addWidget(multiple);
    layout4->addWidget(oneOverX);
    QHBoxLayout* layout5 = new QHBoxLayout;
    layout5->addWidget(one);
    layout5->addWidget(two);
    layout5->addWidget(three);
    layout5->addWidget(minus);
    QHBoxLayout* layout6 = new QHBoxLayout;
    layout6->addWidget(zero);
    layout6->addWidget(point);
    layout6->addWidget(plus);
    layout6->addWidget(equal);

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addWidget(console);
    mainLayout->addLayout(layout1);
    mainLayout->addLayout(layout2);
    mainLayout->addLayout(layout3);
    mainLayout->addLayout(layout4);
    mainLayout->addLayout(layout5);
    mainLayout->addLayout(layout6);
    setLayout(mainLayout);

    setWindowTitle("Calculator");
    setFixedHeight(sizeHint().height());

    connect(one, SIGNAL(clicked()), this, SLOT(Clicknumbers1()));
    connect(two, SIGNAL(clicked()), this, SLOT(Clicknumbers2()));
    connect(three, SIGNAL(clicked()), this, SLOT(Clicknumbers3()));
    connect(four, SIGNAL(clicked()), this, SLOT(Clicknumbers4()));
    connect(five, SIGNAL(clicked()), this, SLOT(Clicknumbers5()));
    connect(six, SIGNAL(clicked()), this, SLOT(Clicknumbers6()));
    connect(seven, SIGNAL(clicked()), this, SLOT(Clicknumbers7()));
    connect(eight, SIGNAL(clicked()), this, SLOT(Clicknumbers8()));
    connect(nine, SIGNAL(clicked()), this, SLOT(Clicknumbers9()));
    connect(zero, SIGNAL(clicked()), this, SLOT(Clicknumbers0()));
    connect(plus, SIGNAL(clicked()), this, SLOT(ClickPlus()));
    connect(minus, SIGNAL(clicked()), this, SLOT(ClickMinus()));
    connect(multiple, SIGNAL(clicked()), this, SLOT(ClickMultiple()));
    connect(divide, SIGNAL(clicked()), this, SLOT(ClickDivide()));
    connect(sqrt, SIGNAL(clicked()), this, SLOT(ClickSqrt()));
    connect(equal, SIGNAL(clicked()), this, SLOT(ClickEqual()));
    connect(point, SIGNAL(clicked()), this, SLOT(ClickPoint()));
    connect(C, SIGNAL(clicked()), this, SLOT(ClickClear()));
}

void CalcGUIdialog::ClickClear(){
    QString text = console->text();
    c.clear();
    text.clear();
    console->setText(text);
}

void CalcGUIdialog::Clicknumbers1(){
    QString text = console->text();
    if(c.getOper() != Calculator::NONE){
            text.clear();
    }
    text.push_back("1");
    console->setText(text);
}

void CalcGUIdialog::Clicknumbers2(){
    QString text = console->text();
    if(c.getOper() != Calculator::NONE){
            text.clear();
    }
    text.push_back("2");
    console->setText(text);
}

void CalcGUIdialog::Clicknumbers3(){
    QString text = console->text();
    if(c.getOper() != Calculator::NONE){
            text.clear();
    }
    text.push_back("3");
    console->setText(text);
}

void CalcGUIdialog::Clicknumbers4(){
    QString text = console->text();
    if(c.getOper() != Calculator::NONE){
            text.clear();
    }
    text.push_back("4");
    console->setText(text);
}

void CalcGUIdialog::Clicknumbers5(){
    QString text = console->text();
    if(c.getOper() != Calculator::NONE){
            text.clear();
    }
    text.push_back("5");
    console->setText(text);
}

void CalcGUIdialog::Clicknumbers6(){
    QString text = console->text();
    if(c.getOper() != Calculator::NONE){
            text.clear();
    }
    text.push_back("6");
    console->setText(text);
}

void CalcGUIdialog::Clicknumbers7(){
    QString text = console->text();
    if(c.getOper() != Calculator::NONE){
            text.clear();
    }
    text.push_back("7");
    console->setText(text);
}

void CalcGUIdialog::Clicknumbers8(){
    QString text = console->text();
    if(c.getOper() != Calculator::NONE){
            text.clear();
    }
    text.push_back("8");
    console->setText(text);
}

void CalcGUIdialog::Clicknumbers9(){
    QString text = console->text();
    if(c.getOper() != Calculator::NONE){
            text.clear();
    }
    text.push_back("9");
    console->setText(text);
}

void CalcGUIdialog::Clicknumbers0(){
    QString text = console->text();
    if(c.getOper() != Calculator::NONE){
        text.clear();
    }
    text.push_back("0");
    console->setText(text);
}

void CalcGUIdialog::ClickPoint(){
    QString text = console->text();
    if(!text.contains("."))
        text.push_back(".");
    console->setText(text);
}

void CalcGUIdialog::ClickPlus(){
    QString text = console->text();
    bool ok;
    double x = text.toDouble(&ok);
    if(ok) {
        c.store(x);
        double answer;
        if(c.getOper() != Calculator::NONE){
            answer = c.equalsPressed();
        }
        else{
            answer = c.handleOperation(Calculator::ADD);
        }
        text = QString::number(answer);
        console->setText(text);
    }
}

void CalcGUIdialog::ClickMinus(){
    QString text = console->text();
    bool ok;
    double x = text.toDouble(&ok);
    if(ok) {
        c.store(x);
        double answer;
        if(c.getOper() != Calculator::NONE){
            answer = c.equalsPressed();
        }
        else{
            answer = c.handleOperation(Calculator::SUBTRACT);
        }
        text = QString::number(answer);
        console->setText(text);
    }
}
void CalcGUIdialog::ClickMultiple(){
    QString text = console->text();
    bool ok;
    double x = text.toDouble(&ok);
    if(ok) {
        c.store(x);
        double answer;
        if(c.getOper() != Calculator::NONE){
            answer = c.equalsPressed();
        }
        else{
            answer = c.handleOperation(Calculator::MULTIPLY);
        }
        text = QString::number(answer);
        console->setText(text);
    }
}
void CalcGUIdialog::ClickDivide(){
    QString text = console->text();
    bool ok;
    double x = text.toDouble(&ok);
    if(ok) {
        c.store(x);
        double answer;
        if(c.getOper() != Calculator::NONE){
            answer = c.equalsPressed();
        }
        else{
            answer = c.handleOperation(Calculator::DIVIDE);
        }
        text = QString::number(answer);
        console->setText(text);
    }
}
void CalcGUIdialog::ClickSqrt(){
    QString text = console->text();
    bool ok;
    double x = text.toDouble(&ok);
    if(ok) {
        c.store(x);
        double answer = c.handleOperation(Calculator::SQRT);
        text = QString::number(answer);
        console->setText(text);
    }
}
void CalcGUIdialog::ClickEqual(){
    QString text = console->text();
    bool ok;
    double x = text.toDouble(&ok);
    if(ok) {
        c.store(x);
        double answer = c.equalsPressed();
        text = QString::number(answer);
        console->setText(text);
    }
}
