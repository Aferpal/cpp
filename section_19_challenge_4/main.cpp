// Section 19
// Challenge 4
// Copy Romeo and Juliet with line numbers
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using std::string;
int main() {
    const string readFileName="./romeoandjuliet.txt";
    const string copyFileName="./numberedromeoandjuliet.txt";
    std::ifstream readFile{readFileName};
    std::ofstream copyFile{copyFileName};
    if(!readFile){
        std::cerr<<"Error loading reading file\n";
        return 1;
    }
    if(!copyFile){
        std::cerr<<"Error loading copy file\n";
        return 1;
    }
    string line;
    int lineNumber=0;
    while(std::getline(readFile, line)){
        if(line!=""){
            ++lineNumber;
            copyFile<<std::setw(5)<<std::left<<lineNumber<<line<<"\n";
        }else{
            copyFile<<line<<"\n";
        }
        
    }
    readFile.close();
    copyFile.close();
    return 0;
}

