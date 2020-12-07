#ifndef _MOVIE_H
#define _MOVIE_H

#include <string>

enum Rate : int{G, PG, PG_13, R};

class Movie{
private:
    std::string name;
    Rate rating;
    int watchedTimes;

public:
    //Movie constructors
    Movie(std::string name = "movie", Rate rating = Rate::G);
    //movie distructor
    ~Movie();

    //getters and setters    
    std::string getName()const{return this->name;}
    Rate getRating()const {return this->rating;}    
    int getWatchedTimes()const {return this->watchedTimes;}
    void setName(std::string name){this->name = name;}
    void setRating(Rate rating){this->rating = rating;}

    // movie methods
    void incrementWatchedTimes();
};

#endif