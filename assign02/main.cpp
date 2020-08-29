//----------------------------------------------------------
// CS260 Assignment 2 Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may not be republished without approval.
//----------------------------------------------------------
#include <iostream>
#include <ctime>

#include "Address.h"
#include "ArrayList.h"
#include "AddressArrayList.h"
#include "AddressLinkedList.h"

using namespace std;


int main()
{
    int size = 0;
    cout << "Enter problem size:" << endl;
    cin >> size;

    ArrayList<Address> aListA;
    ArrayList<Address> aListB;

    AddressFactory aFactory("25000AddressesA.txt");
    AddressFactory aFactory2("25000AddressesB.txt");

    for(int i = 0; i < size / 2; i++) {
        Address a = aFactory.getNext();
        aListA.insertEnd(a);
        Address a2 = aFactory2.getNext();
        aListB.insertEnd(a2);
    }

//Q1
    cout << "-----------------------------Section 1----------------------------" << endl;

    aListA.combine(aListB);
    cout << "aListA has: " << aListA.listSize() << endl;
    cout << "aListB has: " << aListB.listSize() << endl; cout << endl;
    printListRange(aListA, size / 2 - 2, size / 2 + 1);
//    for(int i = size / 2 - 2; i <= size / 2 + 1; i++){
//        cout << aListA.retrieveAt(i) << endl;
//    }

//Q2
    cout << "-----------------------------Section 2----------------------------" << endl;

    Address searchAddress;
    searchAddress.state = "OR";
    ArrayList<Address> aListC = aListA.extractAllMatches(searchAddress);
    cout << "aListA has: " << aListA.listSize() << endl;
    cout << "aListC has: " << aListC.listSize() << endl;
//    cout << endl;
//    printListRange(aListC, 0, aListC.listSize() - 1);

//Q3
    cout << "-----------------------------Section 3----------------------------" << endl;

    AddressLinkedList linkListA;
    AddressLinkedList linkListB;

    AddressFactory aFactory3("25000AddressesA.txt");
    AddressFactory aFactory4("25000AddressesB.txt");

    for(int i = 0; i < size / 2; i++) {
        Address a3 = aFactory3.getNext();
        linkListA.insertEnd(a3);
        Address a4 = aFactory4.getNext();
        linkListB.insertEnd(a4);
    }

    linkListA.printRange(3,5);
    linkListB.printRange(3,5);

//Q4
    cout << "-----------------------------Section 4----------------------------" << endl;

    AddressLinkedList linkListC(linkListA);
    AddressLinkedList linkListD(linkListB);
    linkListC.combine(linkListD);

    cout << "linkListC has: " << linkListC.listSize() << endl;
    cout << "linkListD has: " << linkListD.listSize() << endl;
    linkListC.printRange(size / 2 - 2, size / 2 + 1);

//Q5
    cout << "-----------------------------Section 5----------------------------" << endl;
    AddressLinkedList linkListE = linkListC.extractAllMatches(searchAddress);

    cout << "linkListC has: " << linkListC.listSize() << endl;
    cout << "linkListE has: " << linkListE.listSize() << endl;
    cout << endl;

    linkListE.printRange(0,1);

//Q6
    cout << "-----------------------------Section 6----------------------------" << endl;

    linkListA.interleave(linkListB);

    linkListA.printRange(0,4);

    return 0;
}
