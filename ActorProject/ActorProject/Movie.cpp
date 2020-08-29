#include "Movie.h"
#include <iostream>

using namespace std;

Movie::Movie()
{
}

Movie::Movie(const string theTitle, const int numberActors){
    title = theTitle;
    numActors = 0;
    maxActors = numberActors;
    actors = new Actor*[numberActors]{nullptr};
}

void Movie::print(){
    cout << title << endl;
    cout << endl;
    for (int i = 0; i < numActors; i++){
        cout << actors[i]->getInfo() << endl;
    }
    cout << endl;
}

void Movie::addActor(Actor* person){
    if (numActors >= maxActors){
        exit(0);
    }

    actors[numActors] = person;
    numActors++;
}

Movie::~Movie(){
    delete [] actors;
}
