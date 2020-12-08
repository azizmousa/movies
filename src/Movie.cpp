#include <iostream>
#include "movies/Movie.h"

const std::string Movie::EMPTY_MOVIE{"null"};

//constructor
Movie::Movie(std::string name, Rate rating, int watchedTimes)
    : name{EMPTY_MOVIE}, rating{Rate::NUN}, watchedTimes{0}{
        this->name = name;
        this->rating = rating;
        this->watchedTimes = watchedTimes;
}

//distructor
Movie::~Movie(){}

//increment whatched times by 1
void Movie::incrementWatchedTimes(){this->watchedTimes++;}

//display the movie object
void Movie::display()const {
    std::cout << "Mvoie Name: " <<this->getName() << "\tMovie Rate: " << this->getRating() 
            << "\tWatched Times: " << this->getWatchedTimes() << std::endl; 
}