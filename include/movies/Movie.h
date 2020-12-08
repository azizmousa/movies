#ifndef _MOVIE_H
#define _MOVIE_H

#include <string>

enum Rate : int{NUN, G, PG, PG_13, R};

class Movie{
private:
    std::string name;
    Rate rating;
    int watchedTimes;

public:
    static const std::string EMPTY_MOVIE;
    //Movie constructors
    Movie(std::string name = EMPTY_MOVIE, Rate rating = Rate::NUN, int watchedTimes = 0);
    //movie distructor
    ~Movie();

    //getters and setters    
    std::string getName()const{return this->name;}
    Rate getRating()const {return this->rating;}    
    int getWatchedTimes()const {return this->watchedTimes;}
    void setName(std::string name){this->name = name;}
    void setRating(Rate rating){this->rating = rating;}
    void setWatchedTimes(int watchedTimes){this->watchedTimes = watchedTimes;}

    // movie methods
    void incrementWatchedTimes();
    void display()const;
};

#endif