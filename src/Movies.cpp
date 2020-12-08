#include <iostream>
#include "movies/Movies.h"

//constructors
Movies::Movies(MoviesList *moviesList)
    : moviesList{nullptr}{
        this->moviesList = moviesList;
}

Movies::Movies(){
    this->moviesList = new MoviesList{};
}

//distructor
Movies::~Movies(){
    delete this->moviesList;
}

//insert new movie using the object
bool Movies::insertMovie(Movie movie){
    if(this->moviesList->find(movie.getName())->first == movie.getName())
        return false;
    this->moviesList->insert(std::pair<std::string, Movie>{movie.getName(), movie});
    return true;
}

//insert new movie using the attributes
bool Movies::insertMovie(std::string name, Rate rating, int watchedTimes){
    Movie movie{name, rating, watchedTimes};
    return this->insertMovie(movie);
}

//diplay the movies list
void Movies::displayMovies() const{
    std::cout << "=====================================================" << std::endl;
    for(MoviesList::iterator it{moviesList->begin()}; it != this->moviesList->end(); it++){
        it->second.display();
    }
    std::cout << "=====================================================" << std::endl;
}

// delete existing movie
bool Movies::deleteMovie(std::string name){
    if(this->moviesList->find(name)->first != name)
        return false;
    this->moviesList->erase(name);
    return true;
}

//increment the whatched counter by 1
bool Movies::incrementWatchedCount(std::string name){
    if(this->moviesList->find(name)->first != name)
        return false;
    this->moviesList->find(name)->second.incrementWatchedTimes();
    return true;
}