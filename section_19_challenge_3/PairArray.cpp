#include "PairArray.h"
#include <cstring>

PairArray::PairArray(): temp{nullptr}, data{nullptr}, _size{0}, _length{0}{}
void PairArray::add(const Pair& pair){
    if(_length>=_size){
        if(data==nullptr){
            data=new Pair[2];
            _size=2;
            _length++;
            *(data+_length-1)=pair;
        }else{
            temp=data;
            data= new Pair[_size*2];
            for (int i = 0; i < _length; i++) {
                *(data + i) = *(temp + i);
            }
            _size=_size*2;
            _length++;
            *(data+_length-1)=pair;
            delete[] temp;
        }
        
        std::cout<<"Increased size of pairArray"<<std::endl;
    }else{
        _length++;
        *(data+_length-1)=pair;
    }
}
int PairArray::getValueByName(std::string name){
    for(int i=0; i<_length; i++){
        if((data+i)->name==name){
            return (data+i)->value;
        }
    }
    return 0;
}
void PairArray::display(){
    std::cout<<"Printing Actual Pairs in PairArray: ====================\n";
    for(int i=0; i<_length; i++){
        std::cout<<*(data+i);
    }
}
PairArray::~PairArray(){
    if(data!=nullptr){
        delete[] data;
    }
    if(temp!=nullptr){
        delete[] temp;
    }
    std::cout<<"Destructing pair array";
}