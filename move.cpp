#include "move.h"
#include<iostream>
using namespace std;

Move::Move(int _data){
    cout<< "normal constructor at "<<_data<<endl;
    data= new int{_data}; 
}

Move::Move(const Move& other){
    cout<<"deep copy constructor for "<<*other.data<<endl;
    data= new int{0};
    *data=*(other.data);
}
Move::Move(Move&& other):data(other.data){
    cout<<"move constructor at "<<*other.data<<endl;
    other.data=nullptr;
}

int Move::getData()const{
    return *data;
}

void Move::setData(int newData){
    *data=newData;
}

Move::~Move(){
    if(data!=nullptr){
        cout<<"Calling destructor at "<< *data<<endl;
    }else{
        cout<<"Destrictor nullptr"<<endl;
    }
    
    delete data;
}