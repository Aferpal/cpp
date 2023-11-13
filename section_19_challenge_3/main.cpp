// Section 19
// Challenge 3
// Word counter
#include <iostream>
#include <fstream>
#include "PairArray.h"

using std::string;

Pair search(std::string& file){
    std::ifstream in_file{file};
    if(!in_file){
        std::cerr<<"Unable to find or open the file "<<file<<std::endl;
        return {};
    }
    std::string word;
    std::string w;
    int matches=0;
    std::cout<<"What word would you like to search? ";
    std::cin>>word; std::cout<<"\n";
    while(in_file>>w){
        if(w.find(word)!=std::string::npos){
            matches++;
        }
    }
    in_file.close();
    return {word, matches};
}

int main() {
    PairArray myPairArray;
    std::string file="./romeoandjuliet.txt";
    
    
    for( int i=0; i<5; i++){
        Pair pair=search(file);
        myPairArray.add(pair);
    }
    
    
    myPairArray.display();
    
    return 0;
}

