#include<iostream>

int getCharSize(char* string){
    int size=0;
    do{
        size++;
    }while((*(string+size)) != '\0');
    return (size);
}


int main(){
    char string[]="Hola";
    std::cout<< getCharSize(string);
    return 0;
}