#include "String.h"
#include <string.h>
#include <cctype>
#include <iostream>
String::String(const char* data):data{nullptr}{
    std::cout<<"Normal init with pointer for "<<*data<<"\n";
    this->data=new char[strlen(data+1)];
    strcpy(this->data, data);
}
String::String(const String& other):data{nullptr}{
    this->data=new char[strlen(other.data+1)];
    strcpy(this->data, other.data);
    std::cout<<"Deep copy constructor for "<<*data<<"\n";
}
String::String(String&& other): data{other.data}{
    std::cout<<"Move constructor called for "<<*data<<"\n";
    other.data=nullptr;
}
String::~String(){
    if(data==nullptr){
        std::cout<<"Destructor for nullptr"<<"\n";
    }else{
        std::cout<<"Destructor for "<<*data<<"\n";
        delete []data;
    }
    
}

String String::operator-(){
    char* buffer=new char[strlen(data+1)];
    for(size_t i=0; i<strlen(data); i++){
        *(buffer+i)=std::tolower(*(data+i));
    }
    String lowerCaseString{buffer};
    delete[] buffer;
    return lowerCaseString;
}

bool String::operator==(const String& other){
    return (strcmp(data, other.data)==0);
}

bool String::operator!=(const String& other){
    return (strcmp(data, other.data)!=0);
}
bool String::operator<(const String& other){
    return (strcmp(data, other.data)<0);
}
bool String::operator>(const String& other){
    return (strcmp(data, other.data)>0);
}
String String::operator +(const String& other){
    return String{strcat(data, other.data)};
};
void String::operator+=(const String& other){
    data=strcat(data, other.data);
}
String String::operator*(int n){
    String addedString{""};
    for(size_t i=0; i<n; i++){
        addedString+=(*this);
    }
    return addedString;
};

void String::operator*=(int n){
    String tempString=*this;
    for(size_t i=0; i<n; i++){
        (*this)+=tempString;
    }
    tempString.~String();
};
void String::printSelf(){
    std::cout<<"{Data: ";
    for(int i=0; i<strlen(data); i++){
        std::cout<<*(data+i);
    }
    std::cout<<"}\n";
}