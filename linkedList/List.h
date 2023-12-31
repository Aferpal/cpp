#pragma once
#include "Node.h"
#include<iostream>

namespace lst{

    enum class LTE{START, END};

    class List{
        friend std::ostream& operator<<(std::ostream& os, List& l){
            os<<"Printing list: \n";
            l.iterator=l.start;
            while(l.iterator!=nullptr){
                os<<l.iterator->getVal()<<"->";
                l.iterator=l.iterator->getNext();
            }
            os<<"end"<<'\n';
            return os;
        }
        private:
            Node* start;
            Node* end;
            Node* iterator;
            int _length;
            int appendEnd(int);
            int appendStart(int);
            int popEnd();
            int popStart();
        public:
            List();
            List(Node*);
            int length()const{return _length;}
            Node* operator[](int);
            int append(int, LTE);
            int pop(LTE);
            void remove(int);
            int insert(int , int);
            ~List();
    };

}
