#include "List.h"


void menu(){
    std::cout<<"This is the menu: \n\t1.Insert Element on the list.\n\t2.Delete element from the list.\n\t3.Print list.\n\t4.Exit\n";
}

int main(){
    lst::List myList;
    std::cout<<myList;
    myList.append(5, lst::LTE::START);
    myList.append(6, lst::LTE::END);
    myList.append(4, lst::LTE::START);
    std::cout<<myList; //4, 5, 6
    myList.pop(lst::LTE::END);
    myList.pop(lst::LTE::START);
    myList.append(25, lst::LTE::END); //5, 25
    std::cout<<myList;
    myList.remove(5);
    myList.append(3, lst::LTE::START);
    std::cout<<myList;
    std::cout<<"First element "<<myList[0]->getVal()<<"\n";

    return 0;
}