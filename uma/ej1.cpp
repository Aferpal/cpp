#include <iostream>

double calcSfactor(double index, double x){
    double res=(x/index);
    for(int i=1; i<index; i++){
        res*=x;
        if(!(i%2)){
            res/=i;
        }else{
            res*=i;
        }
    }
    return res;
}

double calcS(double x, int precision){
    double res=0;
    for(int i=1; i<=((precision*2)-1); i+=2){
        res+=calcSfactor(i, x);
    }
    return res;
}


int main(){
    double n;
    int t;
    std::cout<<"Introduzca el valor de X: [0...1]: ";
    std::cin>>n;
    std::cout<<"Introduzca la precision del calculo (numero entero entre 1 y 7): ";
    std::cin>>t;
    std::cout<<"Serie: "<<calcS(n, t);
    return 0;
}