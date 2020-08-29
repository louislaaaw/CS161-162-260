#ifndef ACTORLIST_H
#define ACTORLIST_H

#include "Actor.h"

class ActorList
{
public:
    //Creates list of actors by reading in text file
    ActorList();
    ActorList(const ActorList& otherList);
    Actor* getActorByIndex(int n) const;
    ~ActorList();
private:
    Actor* actors;
    int numActors;
};

#endif // ACTORLIST_H
