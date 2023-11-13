#pragma once

#include "Movie.h"
#include <vector>
#include <string>

class Movies{
private:
std::vector<Movie> movieList;
public:
    Movies(std::string, int, int);
    Movies();
    void addMovie(std::string, int, int);
    void incrementWatchedByName(std::string);
    void displayAll();
    bool checkIfMovieIsAlreadyOnList(std::string);
};