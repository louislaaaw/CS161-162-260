#include <iostream>
#include "set.h"

using namespace std;

int main()
{
    Set<string> mySet;
    mySet.add("Damn");
    mySet.add("it");
    mySet.add("Computer");
    mySet.add("Science");
    mySet.add("Puto");
    cout << mySet.toString() << endl;
    return 0;
}
