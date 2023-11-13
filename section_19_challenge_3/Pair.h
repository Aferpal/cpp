#include <string>
#include <iostream>
struct Pair{
    friend std::ostream& operator<<(std::ostream& os, const Pair& obj);
    std::string name;
    int value;
};
