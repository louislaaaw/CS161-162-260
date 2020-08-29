//----------------------------------------------------------
// CS260 Assignment Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may not be republished without approval.
//----------------------------------------------------------
#include <iostream>
#include <ctime>
#include <random>
#include <ctime>

#include "MySet.h"

using namespace std;



int main()
{
    int size;
    cout << "Enter problem size:";
    cin >> size;

    cout << "-----------Section 1-----------" << endl;
    MySet<int> setA;

    //make RNG
    default_random_engine generator;
    generator.seed(1);            //same sequence each time

    //setup uniform mapping from 1-100,000
    uniform_int_distribution<int> distribution(1,100000);

    for(int i = 0; i < size; i++) {
        setA.add(distribution(generator));
    }

    cout << "Size: " << setA.size() << endl;
    cout << "Depth: " << setA.depth() << endl;

    for(int i = 50000; i < 60000; i++) {
        setA.remove(i);
    }

    cout << "Size after removals: " << setA.size() << endl;

//Q2
//    clock_t startClock = clock();

    cout << "-----------Section 2-----------" << endl;
//    for(int i = 0; i < 10; i++){
    for(int i = 0; i < 5; i++){
        cout << "The largest value is: " << setA.getLargest() << endl;
        setA.remove(setA.getLargest());
    }
//    }

//    clock_t clockDuration = clock() - startClock;
//    double seconds = 1.0 * clockDuration / CLOCKS_PER_SEC;
//    cout << "In " << seconds << " seconds" << endl;



//Q3
    cout << "-----------Section 3-----------" << endl;

    MySet<int> setB; //multiples of 2
    MySet<int> setC; //multiples of 5

    int sizeB;
    cout << "Enter problem size:";
    cin >> sizeB;

    for(int i = 1; i <= size; i++) {
        setB.add(i * 2);
        setC.add(i * 5);
    }

    MySet<int> intersection = setB.intersectionWith(setC);

    cout << "Intersection size is: " << intersection.size() << endl;
    cout << "Largest item in the intersection is: " << intersection.getLargest() << endl;
}
