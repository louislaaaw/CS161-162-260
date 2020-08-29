#include <iostream>
#include <fstream>
#include <ctime>
#include <cctype>

#include "IndexRecord.h"
#include "IndexMap.h"

using namespace std;

int main()
{
    ifstream inFile;
    inFile.open("GreatExpectations.txt");

    IndexMap book(10);
    int pageNum = 1;
    int wordNum = 1;

    clock_t startClock = clock();

    while(!inFile.eof()){
        string temp;
        inFile >> temp;
        if(inFile.fail()){
            break;
        }
        if(temp.at(0) == '-'){
            pageNum++;
            wordNum = 1;
            continue;
        }
        if(isupper(temp.at(0)))
            temp.at(0) = static_cast<char>(tolower(temp.at(0)));
        book.add(temp, pageNum, wordNum);
        wordNum++;
    }

    clock_t clockDuration = clock() - startClock;
    double seconds = 1.0 * clockDuration / CLOCKS_PER_SEC;
    cout << "In " << seconds << " seconds" << endl;

    cout << "---------------------------------" << endl;

    cout << "Number of Keys: " << book.numKeys() << endl;

    cout << "---------------------------------" << endl;

    IndexRecord fathersRecords = book.get("fathers");
    cout << fathersRecords << endl;

    cout << "---------------------------------" << endl;
    book.findWordPairs("great","expectations");
    cout << endl;

    cout << "---------------------------------" << endl;
    cout << "first word on page 100: " << book.firstWordOnPage(100) << endl;

    return 0;
}
