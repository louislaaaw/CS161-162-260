#include "ActorList.h"
#include <iostream>
#include <fstream>
using namespace std;

ActorList::ActorList(){
    ifstream inFile("actors.txt");

    if(!inFile.is_open()){
        exit(0);
    }

    inFile >> numActors;

    actors = new Actor[numActors];

    for(int i = 0; i < numActors; i++){
        string fname;
        string lname;
        int birthyear;
        inFile >> fname >> lname >> birthyear;

        actors[i] = Actor(fname, lname, birthyear);
    }

    if(!inFile.good()){
        exit(0);
    }
}

ActorList::ActorList(const ActorList& otherList){

    numActors = otherList.numActors;

    actors = new Actor[numActors];

    for(int i = 0; i < numActors; i++){
        actors[i] = otherList.actors[i];
    }
}

Actor* ActorList::getActorByIndex(int n) const{
    return &actors[n];
}

ActorList::~ActorList(){
    delete [] actors;
}
