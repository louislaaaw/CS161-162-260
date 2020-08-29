#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "Person.h"

using namespace std;

Person parsePerson(string dataString){
    Person newStudent;

    int commaLoc = dataString.find(",");
    newStudent.kNum = dataString.substr(0, commaLoc);
    dataString.erase(0, commaLoc + 1);
    commaLoc = dataString.find(",");
    newStudent.last = dataString.substr(0, commaLoc);
    dataString.erase(0, commaLoc + 1);
    commaLoc = dataString.find(",");
    newStudent.first = dataString.substr(0, commaLoc);
    dataString.erase(0, commaLoc + 1);
    newStudent.zipCode = atoi(dataString.c_str());

    return newStudent;
}

void readData(Person studentLists[], int size){
    ifstream inFile;
    inFile.open("people.txt");

    for(int i = 0; i < size; i++){
        string temp;
        getline(inFile, temp);
        studentLists[i] = parsePerson(temp);
    }
}

int main()
{
// part 1
    const int size = 100000;

    Person students[size];

    readData(students,size);

// part 2
    clock_t startTime = clock();

    int numMertz = countLastName("Mertz", students, size);

    clock_t endTime = clock();
    clock_t elapsed = endTime - startTime;

    cout << "-------------Section 2-------------" << endl; cout << endl;
    cout << "Number of 'Mertz': "<< numMertz << endl; cout << endl;

    cout << "It takes: " << 1.000000 * elapsed / CLOCKS_PER_SEC << "s" << endl;

    cout << endl; cout << "-------------Section 3-------------" << endl; cout << endl;

// part 3
    partialZipSort(students, 0, 99);

    for(int i = 0; i < 10; i++){
        cout << students[i].last << "  " << students[i].first << "  " << students[i].zipCode << endl;
    }

    cout << endl; cout << "-------------Section 4-------------" << endl; cout << endl;

// part 4
    clock_t startTime_1 = clock();

    nameSort(students, size);

    clock_t endTime_1 = clock();
    clock_t elapsed_1 = endTime_1 - startTime_1;
    for(int i = 0; i < 10; i++){
        cout << students[i].last << "   "<< students[i].first << endl;
    }

    cout << "It takes: " << 1.0 * elapsed_1 / CLOCKS_PER_SEC << "s" << endl;



    cout << endl; cout << "-------------Section 5-------------" << endl; cout << endl;

// part 5
    int abbottFirst = binaryFindFirstByLastName("Abbott", students, size);
    int ZulaufFirst = binaryFindFirstByLastName("Zulauf", students, size);
    int abbottLast = binaryFindLastByLastName("Abbott", students, size);
    int ZulaufLast = binaryFindLastByLastName("Zulauf", students, size);
    cout << "First Abbott: " << abbottFirst << endl;
    cout << "Last Abbott: " << abbottLast << endl;
    cout << "First Zulauf: " << ZulaufFirst << endl;
    cout << "Last Zulauf: " << ZulaufLast << endl;

    cout << endl; cout << "-------------Section 6-------------" << endl; cout << endl;

// part 6
    clock_t startTime_2 = clock();

    int numMertz_2 = countLastNameInSorted("Mertz", students, size);

    clock_t endTime_2 = clock();
    clock_t elapsed_2 = endTime_2 - startTime_2;

    cout << "Number of 'Mertz': "<< numMertz_2 << endl; cout << endl;
    cout << "It takes: " << 1.000000 * elapsed_2 / CLOCKS_PER_SEC << "s" << endl;

    cout << endl; cout << "-----------------------------------" << endl; cout << endl;

    return 0;
}
