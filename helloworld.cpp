#include <iostream>
#include <vector>
#include <string>
#include "move.h"
using namespace std;

ostream& operator <<(ostream& os, const Move& src){
   os<< src.getData()<<endl;
   return os;
}


int main()
{
    
   vector<Move> move_vector;
   move_vector.push_back(Move{10});
   move_vector.push_back(Move{20});
   move_vector.push_back(Move{30});
   cout<< "end of program execution"<<endl;
   return 0;
}