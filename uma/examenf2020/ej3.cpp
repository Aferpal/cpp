#include<iostream>
#include<array>
#include<string>
struct Person{
    std::string name;
    double money;
};
struct APersonas{
    std::array<Person, 10> data={};
    int length=0;
};


double getAverageMoney(const APersonas& arr){
    double sum=0.0;
    for(int i=0; i<arr.length; i++){
        sum+=double(arr.data[i].money/arr.length);
    }
    return sum;
}

int position(const APersonas& arr, const std::string& str){
    int i=0;
    while(i<arr.length && arr.data[i].name!=str){
        i++;
    } 
    return i;
}

void readData(APersonas& arr){
    std::cout<<"Introduzca nombres y gastos (FIN PARA TERMINAR): \n";
    std::cout<<"Nombre: ";
    std::string str; double n; int p;
    std::cin>>str;
    while(str!="FIN"){
        std::cout<<"Gastos: ";std::cin>>n;
        p=position(arr, str);
        if(p=arr.length){
            arr.data[arr.length]=Person{str, n};
        }else{
            arr.data[p].money+=n;
        }
        std::cout<<"Nombre: ";std::cin>>str;
    }
}

void getPeopleDebt(APersonas& a1){
    double av=getAverageMoney(a1);
    for(int i=0; i<a1.length; i++){
        a1.data[i].money-=av;
    }
}

bool is0(double b){
    return ((b>-(1e-3)) && (b<1e-3));
}

bool areEqual(const APersonas& arr){
    int i=0;
    while(i<arr.length && is0(arr.data[i++].money)){}
    return i==arr.length;
}

void moveToEqual(APersonas& arr){
    for(int i=0; i<arr.length; i++){
        if(arr.data[i].money>0){
            std::cout<<arr.data[i].name<<" recibe";
        }
        arr.data[i+1].money+=arr.data[i].money;
        arr.data[i].money=0;
    }
}

int main(){
    return 0;
}