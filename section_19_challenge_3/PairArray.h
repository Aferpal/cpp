#include "Pair.h"
class PairArray{
    private:
        Pair* data;
        Pair* temp;
        int _size;
        int _length;
    public:
        PairArray();
        void add(const Pair& data);
        int getValueByName(std::string name);
        int length(){return _length;};
        void display();
        ~PairArray();

};