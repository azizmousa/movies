#include <iostream>
#include "movies/Movies.h"

Movies::Movies(MoviesList *moviesList)
    : moviesList{nullptr}{
        this->moviesList = moviesList;
}

Movies::Movies(){
    this->moviesList = new MoviesList{};
}

Movies::~Movies(){
    delete this->moviesList;
}

bool Movies::insertMovie(Movie movie){
    if(this->moviesList->find(movie.getName())->first == movie.getName())
        return false;
    this->moviesList->insert(std::pair<std::string, Movie>{movie.getName(), movie});
    return true;
}

bool Movies::insertMovie(std::string name, Rate rating){
    Movie movie{name, rating};
    return this->insertMovie(movie);
}

void Movies::displayMovies() const{
    std::cout << "=====================================================" << std::endl;
    for(MoviesList::iterator it{moviesList->begin()}; it != this->moviesList->end(); it++){
        std::cout << "Mvoie Name: " <<it->second.getName() << "\tMovie Rate: " << it->second.getRating() 
            << "\tWatched Times: " << it->second.getWatchedTimes() << std::endl; 
    }
    std::cout << "=====================================================" << std::endl;
}

bool Movies::deleteMovie(std::string name){
    if(this->moviesList->find(name)->first != name)
        return false;
    this->moviesList->erase(name);
    return true;
}

bool Movies::incrementWatchedCount(std::string name){
    if(this->moviesList->find(name)->first != name)
        return false;
    this->moviesList->find(name)->second.incrementWatchedTimes();
    return true;
}