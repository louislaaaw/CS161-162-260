#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLayout>
#include <QLabel>
#include <QLineEdit>
#include <QString>

#include "CalcGUIdialog.h"

using namespace std;

int main(int argc, char* argv[])
{
    QApplication calc(argc, argv);

    CalcGUIdialog calculator;
    calculator.show();
    QWidget* window = new QWidget;
    window->setWindowTitle("Calculator");

    QLineEdit* console = new QLineEdit("0");

    QPushButton* MC = new QPushButton("MC");
    QPushButton* MR = new QPushButton("MR");
    QPushButton* MS = new QPushButton("MS");
    QPushButton* MPlus = new QPushButton("M+");
    QPushButton* MMinus = new QPushButton("M-");
    QPushButton* Back = new QPushButton("←");
    QPushButton* CE = new QPushButton("CE");
    QPushButton* C = new QPushButton("C");
    QPushButton* plusOrMinus = new QPushButton("±");
    QPushButton* sqrt = new QPushButton("√");
    QPushButton* seven = new QPushButton("7");
    QPushButton* eight = new QPushButton("8");
    QPushButton* nine = new QPushButton("9");
    QPushButton* divide = new QPushButton("/");
    QPushButton* percent = new QPushButton("%");
    QPushButton* four = new QPushButton("4");
    QPushButton* five = new QPushButton("5");
    QPushButton* six = new QPushButton("6");
    QPushButton* multiple = new QPushButton("*");
    QPushButton* oneOverX = new QPushButton("1/x");
    QPushButton* one = new QPushButton("1");
    QPushButton* two = new QPushButton("2");
    QPushButton* three = new QPushButton("3");
    QPushButton* minus = new QPushButton("-");
    QPushButton* zero = new QPushButton("0");
    QPushButton* point = new QPushButton(".");
    QPushButton* plus = new QPushButton("+");
    QPushButton* equal = new QPushButton("=");

    QObject::connect(one, SIGNAL(clicked(bool)), &calc, SLOT(convert(console)));
    QObject::connect(two, SIGNAL(clicked(bool)), &calc, SLOT(convert(console)));
    QObject::connect(three, SIGNAL(clicked(bool)), &calc, SLOT(convert(console)));
    QObject::connect(four, SIGNAL(clicked(bool)), &calc, SLOT(convert(console)));
    QObject::connect(five, SIGNAL(clicked(bool)), &calc, SLOT(convert(console)));
    QObject::connect(six, SIGNAL(clicked(bool)), &calc, SLOT(convert(console)));
    QObject::connect(seven, SIGNAL(clicked(bool)), &calc, SLOT(convert(console)));
    QObject::connect(eight, SIGNAL(clicked(bool)), &calc, SLOT(convert(console)));
    QObject::connect(nine, SIGNAL(clicked(bool)), &calc, SLOT(convert(console)));
    QObject::connect(plus, SIGNAL(clicked(bool)), &calc, SLOT(Calculator::handleOperation(Calculator::ADD)));
    QObject::connect(minus, SIGNAL(clicked(bool)), &calc, SLOT(Calculator::handleOperation(Calculator::SUBTRACT)));
    QObject::connect(multiple, SIGNAL(clicked(bool)), &calc, SLOT(Calculator::handleOperation(Calculator::MULTIPLY)));
    QObject::connect(divide, SIGNAL(clicked(bool)), &calc, SLOT(Calculator::handleOperation(Calculator::DIVIDE)));
    QObject::connect(sqrt, SIGNAL(clicked(bool)), &calc, SLOT(Calculator::handleOperation(Calculator::SQRT)));
    QObject::connect(equal, SIGNAL(clicked(bool)), &calc, SLOT(Calculator::equalsPressed()));
    QObject::connect(point, SIGNAL(clicked(bool)), &calc, SLOT());
    QObject::connect(Back, SIGNAL(clicked(bool)), &calc, SLOT(Calculator::clear()));

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

    window->setLayout(mainLayout);

    window->show();


    return calc.exec();
}
