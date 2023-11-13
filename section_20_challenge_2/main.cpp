// Section 20
// Challenge 2
//  Lists

#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include <iomanip>
#include <limits>

class Song {
    friend std::ostream &operator<<(std::ostream &os, const Song &s);
    std::string name;
    std::string artist;
    int rating;
public:
    Song() = default;
    Song(std::string name, std::string artist, int rating)
            : name{name}, artist{artist}, rating{rating} {}
    std::string get_name() const {
        return name;
    }
    std::string get_artist() const {
        return artist;
    }
    int get_rating() const {
        return rating;
    }
    
    bool operator<(const Song &rhs) const  {
        return this->name < rhs.name;
    }
    
    bool operator==(const Song &rhs) const  {
        return this->name == rhs.name;
    }
};

std::ostream &operator<<(std::ostream &os, const Song &s) {
    os << std::setw(20) << std::left << s.name
       << std::setw(30) << s.artist
       << std::setw(2) << s.rating;
       return os;
}

void display_menu() {
    std::cout << "\nF - Play First Song" << std::endl;
    std::cout << "N - Play Next song" << std::endl;
    std::cout << "P - Play Previous song" << std::endl;
    std::cout << "A - Add and play a new Song at current location" << std::endl;
    std::cout << "L - List the current playlist" << std::endl;
    std::cout << "===============================================" << std::endl;
    std::cout << "Enter a selection (Q to quit): ";
}
void play_current_song(const Song &song) {
   std::cout<<"Playing: "<<song<<"\n";
}
void play_first_song(std::list<Song>& playlist, std::list<Song>::iterator& it){
    it=playlist.begin();
    play_current_song(*it);
}

void play_next_song(std::list<Song>& playlist, std::list<Song>::iterator& it){
    if(!(*(it)==playlist.back()))
        it++;
    else
        it=playlist.begin();
        
    play_current_song(*it);
}

void play_previous_song(std::list<Song>& playlist, std::list<Song>::iterator& it){
    if(it!=playlist.begin())
        it--;
    else
        it=playlist.end();
        it--;
    play_current_song(*it);
}
void add_new_song(std::list<Song>& playlist, std::list<Song>::iterator& it){
    std::string name, author;
    int rating;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout<<"Enter song's name: ";
    std::getline(std::cin, name);
    std::cout<<"Enter song's author: ";
    std::getline(std::cin, author);
    std::cout<<"Enter song's rating: ";
    std::cin>>rating;
    playlist.emplace(it, Song{name, author, rating});
    it--;
    play_current_song(*it);
}



void display_playlist(const std::list<Song> &playlist, const Song &current_song) {
    auto itBegin=playlist.begin();
    while (itBegin!=playlist.end()){
        std::cout<<*itBegin<<"\n";
        itBegin++;
    }
    std::cout<<"Current playing song: \n";
    std::cout<<current_song<<"\n\n";
}

int main() {

    std::list<Song> playlist{
            {"God's Plan",        "Drake",                     5},
            {"Never Be The Same", "Camila Cabello",            5},
            {"Pray For Me",       "The Weekend and K. Lamar",  4},
            {"The Middle",        "Zedd, Maren Morris & Grey", 5},
            {"Wait",              "Maroone 5",                 4},
            {"Whatever It Takes", "Imagine Dragons",           3}          
    };
    
    std::list<Song>::iterator current_song = playlist.begin();
    bool exit=false;
    while(!exit){
        char option;
        display_menu();
        std::cin>>option;
        switch (option)
        {
        case 'F':
            play_first_song(playlist, current_song);
            break;
        case 'N':
            play_next_song(playlist, current_song);
            break;
        case 'P':
            play_previous_song(playlist, current_song);
            break;
        case 'A':
            add_new_song(playlist, current_song);
            break;
        case 'L':
            display_playlist(playlist, *current_song);
            break;
        case 'Q':
            exit=true;
            break;
        default:
            break;
        }
    }
    return 0;
}