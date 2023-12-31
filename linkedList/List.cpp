#include "List.h"
using namespace lst;

List::List(){
    this->start=nullptr;
    this->_length=0;
    this->end=nullptr;
    this->iterator=nullptr;
}

List::List(Node* startNode){
    this->start=startNode;
    this->iterator=this->start;
    this->end=startNode;
    _length=0;
    while((this->end)->getNext()!=nullptr){
        this->end=this->end->getNext();
        _length++;
    }
    
}

Node* List::operator[](int index){
    if(index>=_length){
        return nullptr;
    }else{
        this->iterator=this->start;
        int i=0;
        while((i++)<index){
            this->iterator=this->iterator->getNext();
        }
        return this->iterator;
    }
}

int List::appendStart(int val){
        Node* n=new Node(val, this->start);
        this->start=n;
        _length++;
    if(_length==1){
        this->end=n;
    }  
    return 1;
}
int List::appendEnd(int val){
    if(_length==0){
        appendStart(val);
    }else{
        Node* n=new Node(val, nullptr);
        this->end->setNext(n);
        this->end=n;
        _length++;
    }
    return 1;
}

int List::append(int val, LTE s=LTE::END){
    if(s==LTE::START){
        return this->appendStart(val);
    }else if(s==LTE::END){
        return this->appendEnd(val);
    }
    return 0;
}

int List::popStart(){
    if(_length==0){
    }else{
        Node* s= this->start;
        this->start=s->getNext();
        _length--;
        delete s;
    }
    return 1;
}
int List::popEnd(){
    if(_length>1){
        Node* s= this->end;
        this->end=this->operator[](_length-2);
        this->end->setNext(nullptr);
        _length--;
        delete s;
    }else{
        popStart();
    }
    return 1;
}

int List::pop(LTE s=LTE::END){
    if(s==LTE::START){
        return this->popStart();
    }else if(s==LTE::END){
        return this->popEnd();
    }
    return 0;
}

void List::remove(int v){
    this->iterator=this->start;
    Node* prev;
    while((this->iterator)!=nullptr && this->iterator->getVal()!=v){
        prev=this->iterator;
        this->iterator=this->iterator->getNext();
    }
    if(this->iterator!=nullptr){
        if(this->iterator==this->start){
            this->start=this->iterator->getNext();
            delete this->iterator;
        }else{
            prev->setNext(this->iterator->getNext());
            delete this->iterator;
        }
        _length--;
    }
}
List::~List(){
    while(start!=nullptr){
        popStart();
    }
    std::cout<<"Delete complete, current length "<<_length<<"\n";
}