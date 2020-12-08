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
    for(MoviesList::iterator it{moviesList->begin()}; it != this->moviesList->end(); it++){
        std::cout << "Mvoie Name: " <<it->second.getName() << "\t" << "Movie Rate: " << it->second.getRating() << std::endl; 
    }
}