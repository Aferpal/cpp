#include "Array.h"

int main(){
    Array<int> arr;
    arr.push(5);
    arr.push(7);
    arr[1]=10;
    arr.push(20);
    std::cout<<arr<<std::endl;
    return 0;
}