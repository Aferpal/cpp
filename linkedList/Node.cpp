#include "Node.h"

Node::Node(int v, Node* n):value{v}, next{n}{}
Node::Node(const Node& other):value{other.getVal()}, next{other.getNext()}{}
Node::Node(Node&& other):value{other.getVal()}, next{other.getNext()}{other.setNext(nullptr);}
void Node::setNext(Node* n){
    this->next=n;
}
void Node::setVal(int v){
    this->value=v;
}
int Node::getVal()const{return this->value;}
Node* Node::getNext()const{return this->next;}