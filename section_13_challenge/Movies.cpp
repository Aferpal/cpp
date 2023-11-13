#include "Movies.h"
#include "Movie.h"
#include <string>
#include <vector>
#include <iostream>
Movies::Movies(std::string name, int watchedTimes, int movieRatio){
    movieList.push_back(Movie{name, watchedTimes, movieRatio});
}
Movies::Movies(){
    std::cout<<"You instantiated an empty Movie List, to include a new one call {movies object name}.addMovie"<<std::endl;
}
void Movies::addMovie(std::string name, int watchedTimes, int movieRatio){
    if(checkIfMovieIsAlreadyOnList(name)){
        std::cout<<"ERROR MESSAGE:-----The film "<<name<<" is already on your list.----"<<std::endl;
        return;
    }
    movieList.push_back(Movie{name, watchedTimes, movieRatio});
};



void Movies::incrementWatchedByName(std::string name){
    if(!checkIfMovieIsAlreadyOnList(name)){
        std::cout<<"ERROR MESSAGE:-----The film "<<name<<" is not on your list so you cant increment it's watchedTime. Add this film with addMovie() !----"<<std::endl;
        return;
    }
    for(size_t i=0; i<movieList.size(); i++){
        if(movieList[i].getName()==name){
            ++movieList[i];
            break;
        }
    }
};
void Movies::displayAll(){
    for(size_t i=0; i<movieList.size(); i++){
        movieList[i].displaySelf();
    }
};

bool Movies::checkIfMovieIsAlreadyOnList(std::string name){
    for(size_t i=0; i<movieList.size(); i++){
        if(movieList[i].getName()==name){
            return true;
        }

    }
    return false;
}