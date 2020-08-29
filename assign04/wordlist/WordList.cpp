//----------------------------------------------------------
// CS260 Assignment Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may not be republished without approval.
//----------------------------------------------------------

#include <iostream>
#include <fstream>
#include <ctime>
#include "MySet.h"

using namespace std;

int main()
{
    ifstream inFile;
    inFile.open("WordsRandomized.txt");

    MySet<string> set;

    while(!inFile.eof()){
        string temp;
        getline(inFile, temp);
        set.add(temp);
    }

    clock_t startClock = clock();

    vector<string> vec = set.getRange("mo","n");

    clock_t clockDuration = clock() - startClock;
    double seconds = 1.0 * clockDuration / CLOCKS_PER_SEC;
    cout << "In " << seconds << " seconds" << endl;

    for(int i = 0; i < 5; i++){
        cout << vec.at(i) << " ";
    }

    cout << endl;
}
