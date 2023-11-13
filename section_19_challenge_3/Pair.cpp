#include "Pair.h"

std::ostream& operator<<(std::ostream& os, const Pair& obj){
    os<<"Pair: {\n\t"<<"name: "<<obj.name<<", \n\t value: "<<obj.value<<"\n}\n";
    return os;
}