#include<iostream>
#include<array>
#include<string>
const int MAXCHAR=5;
typedef std::array<std::string, 10> TArray;
struct Letter{
    char c;
    TArray data={};
    int length;

};
typedef std::array<Letter, MAXCHAR> AChar;
struct CharArray{
    AChar data={};
    int length=0;
};

bool hasCharArray(const CharArray& arr, char c){
    int i=0;
    while(i<arr.length && c!=arr.data[i++].c){}
    return i!=arr.length;
}

void getPatronLetters(CharArray& arr){
    arr={{}, 0};
    std::string str;
    do{
        std::cout<<"Introduce un patrón máximo de 5 letras: ";
        std::cin>>str;
    }while(str.length()>5);
    for(int i=0; i<str.length(); i++){
        if(!hasCharArray(arr, str[i])){
            arr.data[arr.length++].c=str[i];
        }
    }

}

bool hasLetterWord(const std::string& str, char c){
    int i=0; 
    while(i<str.size() && str[i]!=c){i++;}
    return i!=(str.size());
}

bool hasTArrayString(const Letter& letter, const std::string& str){
    int i=0;
    while(i<letter.length && letter.data[i++]!=str){}
    return i!=letter.length;
}

void readText(CharArray& arr){
    std::cout<<"Introduce un texto acabado en FIN: ";
    std::string str;
    std::cin>>str;
    while(str!="FIN"){
        for(int i=0; i<arr.length; i++){
            if(hasLetterWord(str, arr.data[i].c) && !hasTArrayString(arr.data[i], str)){
                arr.data[i].data[arr.data[i].length++]=str;
            }
        }
        std::cin>>str;
    }
}

void printArr(const CharArray& arr){
    for(int i=0; i<arr.length; i++){
        std::cout<<arr.data[i].c<<": ";
        for(int j=0; j<arr.data[i].length; j++){
            std::cout<<arr.data[i].data[j]<<" ";
        }
        std::cout<<"\n";
    }
}

int main(){
    CharArray cArr;
    getPatronLetters(cArr);
    readText(cArr);
    printArr(cArr);
    return 0;
}