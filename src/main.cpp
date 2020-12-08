#include <iostream>
#include "movies/Movies.h"

// Function prototypes
void increment_watched(Movies &movies, std::string name);
void add_movie(Movies &movies, std::string name, std::string rating, int watched);

/******************************************************************
 * increment_watched expects a reference to a Movies object 
 * and the name of the movie to increment the watched count
 *
 * If the watched count was incremented successfully it
*  displays a success message
*  otherwise the watched count could not be incremented
*  because the name of the movie was not found
 * ***************************************************************/

void increment_watched(Movies &movies, std::string name) {
    if (movies.incrementWatchedCount(name)) {
        std::cout << name << " watch incremented" <<  std::endl;
    } else {
        std::cout << name << " not found" <<  std::endl;
    }
}

/******************************************************************
 * add_movie expects a reference to a Movies object 
 * and the name of the movie, the rating and the watched count
 *
 * If the movie was successfully added to the movies object it
*  displays a success message
*  otherwise the movie was not added 
*  because the name of the movie was already in movies
 * ***************************************************************/
void add_movie(Movies &movies, std::string name, Rate rating, int watched) {
    if (movies.insertMovie(name,rating,watched)) {
        std::cout << name << " added" << std::endl;
    } else {
        std::cout << name << " already exists" <<  std::endl;
    }
}

int main() {
    
    Movies my_movies;
    
    my_movies.displayMovies();
    
    add_movie(my_movies, "Big", Rate::PG_13,2);                 // OK
    add_movie(my_movies,"Star Wars", Rate::PG,5);             // OK
    add_movie(my_movies,"Cinderella", Rate::PG,7);           // OK
     
    my_movies.displayMovies();   // Big, Star Wars, Cinderella
    
    add_movie(my_movies,"Cinderella", Rate::PG,7);            // Already exists
    add_movie(my_movies,"Ice Age", Rate::PG,12);              // OK
 
    my_movies.displayMovies();    // Big, Star Wars, Cinderella, Ice Age
    
    increment_watched(my_movies,"Big");                    // OK
    increment_watched(my_movies,"Ice Age");              // OK
    
    my_movies.displayMovies();    // Big and Ice Age watched count incremented by 1
    
    increment_watched(my_movies,"XXX");         // XXX not found

	return 0;
}