#include"String.h"


int main(){
    String mystr{"HOLA"};
    mystr+="bomba";
    mystr*=2;
    mystr.printSelf();
    return 0;
}