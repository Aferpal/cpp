#pragma once

#include <string>

class Movie{
private:
    std::string name;
    int watchedTimes;
    int movieRating;
public:
    Movie(const Movie&);
    Movie(std::string, int, int);
    Movie(Movie&&);
    void displaySelf();
    std::string& getName();
    void operator++();
};