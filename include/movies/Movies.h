#ifndef _MOVIES_H
#define _MOVIES_H

#include <map>
#include <string>
#include "movies/Movie.h"

typedef std::map<std::string, Movie> MoviesList;

class Movies{
private:
    MoviesList *moviesList;

public:
    //constructors
    Movies();
    Movies(MoviesList *moviesList);

    //distructor
    ~Movies();

    //getters
    MoviesList getMoviesList()const;

    //setters
    void setMoviesList(MoviesList *MoviesList);

    //Movies Methods
    bool insertMovie(Movie movie);
    bool insertMovie(std::string name, Rate rating);
    bool deleteMovie(std::string name);
    bool incrementWatchedCount(std::string name);
    void displayMovies()const;
};

#endif