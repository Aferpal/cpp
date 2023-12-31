#pragma once

class Node{
    private:
        int value;
        int position;
        Node* next;
    public:
        Node(int, Node*);
        Node(const Node&);
        Node(Node&&);
        Node* getNext() const;
        int getVal() const;
        void setVal(int);
        void setNext(Node*);

};