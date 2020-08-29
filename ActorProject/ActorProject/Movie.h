#ifndef MOVIE_H
#define MOVIE_H

#include "Actor.h"

class Movie
{
public:
    Movie();
    Movie(const string theTitle, const int numberActors);
    void print();
    void addActor(Actor* person);
    ~Movie();
private:
    string title;
    Actor** actors;
    int numActors;
    int maxActors;
};

#endif // MOVIE_H
