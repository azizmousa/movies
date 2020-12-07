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
    Movies(const Movies &movies); 
    Movies(const Movies &&movies);

    //distructor
    ~Movies();

    //getters
    MoviesList getMoviesList()const;

    //setters
    void setMoviesList(MoviesList *MoviesList);

    //Movies Methods
    bool insertMovie(Movie movie);
    bool deleteMovie(std::string name);
    bool incrementWatchedCount(std::string name);
    void displayMovies();
};

#endif