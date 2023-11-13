#include<iostream>

int main(){
    int n, max=0, sum;
    std::cout<<"Introduce una serie de numeros positivos acabado en 0: ";
    do{
        std::cin>>n;
        sum=0;
        for(int i=1; i<=(n/2); i++){
            if((n%i)==0){
                sum+=i;
            }
        }
        if(sum==n && n>=max){
            max=n;
        }
    }while(n!=0);
    if(max==0){
        std::cout<<"No hay ningun numero perfecto\n";
    }else{
        std::cout<<"El mayor perfecto es "<<max<<"\n";
    }

    return 0;
}
