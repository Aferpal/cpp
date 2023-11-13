#include<iostream>
#include <fstream>
#include<unordered_map>
#include<string>

std::string decode(std::ifstream& f){
    std::string word;
    std::unordered_map<std::string, int> map;
    int i=0;
    map.rehash(500);
    while(f>>word){
        i++;
        map[word]++;
    }
    word="";
    for(auto it=map.begin(); it!=map.end(); it++){
        word=((it->first)+std::to_string(it->second))+word;
    }
    return word;
}


int main(){
    std::ifstream in_file{"./ej.txt"};
    if(!in_file){
        std::cout<<"Error searching file.\n";
        return 0;
    }
    std::cout<<decode(in_file);

}   