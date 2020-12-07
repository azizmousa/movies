#include "movies/Movie.h"

//constructor
Movie::Movie(std::string name, Rate rating)
    : name{"movie"}, rating{Rate::G}{

}

//distructor
Movie::~Movie(){}

void Movie::incrementWatchedTimes(){this->watchedTimes++;}