#include "Movie.h"
#include <iostream>
Movie::Movie(const Movie& other):name{other.name}, watchedTimes{other.watchedTimes}, movieRating{other.movieRating}{

}
Movie::Movie(Movie&& other):name{other.name}, watchedTimes{other.watchedTimes}, movieRating{other.movieRating}{

}
Movie::Movie(std::string name, int watchedTimes, int movieRating){
    this->name=name;
    this->watchedTimes=watchedTimes;
    this->movieRating=movieRating;
}
void Movie::displaySelf(){
    std::cout<< "------------"<<std::endl;
    std::cout<<"Name: "<<name<<std::endl;
    std::cout<<"Watched Times: "<<watchedTimes<< std::endl;
    std::cout<<"Rating: "<<movieRating<< std::endl; 
}
std::string& Movie::getName(){
    return name;
}

void Movie::operator++(){
    this->watchedTimes++;
}