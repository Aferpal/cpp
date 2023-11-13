#include "Movies.h"


int main(){
    Movies myMovieList;
    myMovieList.addMovie("Piratas del Caribe", 1, 5);
    myMovieList.incrementWatchedByName("adaiwd");
    myMovieList.addMovie("Piratas del Caribe", 1, 5);
    myMovieList.displayAll();
    myMovieList.addMovie("Avatar", 1, 4);
    myMovieList.incrementWatchedByName("Avatar");
    myMovieList.displayAll();
    return 0;
}