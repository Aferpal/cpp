#include <iostream>


void normaliseLimits(int& x1, int& x2){
    if(bool(x1%2)){
        x1+=1;
    }
    if(bool(x2%2)){
        x2-=1;
    }
};
bool isPrime(int x){
    bool res=true;
    for(int i=2; i<=(x/2); i++){
        if(!(x%i)){
            res=false;   
        }
    }
    return res;
}
bool checkGoldBachNumber(int x){
    bool res=false;
    for(int i=1; i<=(x/2) && !res; i++){
        if(isPrime(i) && isPrime(x-i)){
            res=true;
        }
    }
    return res;
}
bool checkGoldBachSeries(int start, int end){
    bool res=true;
    for(int i=start; i<=end && res; i+=2){
        if(!checkGoldBachNumber(i)){
            res=false;
        };
    }
    return res;

}
int main(){
    int start, end;
    bool check;
    std::cout<<"Introduce el limite inferior: ";
    std::cin>>start;
    std::cout<<"Introduce el limite superior: ";
    std::cin>>end;
    normaliseLimits(start, end);
    if(start>end){
        check=checkGoldBachSeries(end, start);
    }else{
        check=checkGoldBachSeries(start, end);
    }
    if(check){
        std::cout<<"Se cumple.\n";
    }else{
        std::cout<<"No se cumple.\n";
    }
    
    return 0;
}