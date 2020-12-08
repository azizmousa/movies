#include "movies/Movie.h"

const std::string Movie::EMPTY_MOVIE{"null"};

//constructor
Movie::Movie(std::string name, Rate rating)
    : name{EMPTY_MOVIE}, rating{Rate::NUN}, watchedTimes{0}{
        this->name = name;
        this->rating = rating;
}

//distructor
Movie::~Movie(){}

void Movie::incrementWatchedTimes(){this->watchedTimes++;}