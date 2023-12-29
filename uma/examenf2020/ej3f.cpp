#include<iostream>
#include<string>
#include<array>
struct Person{
    std::string name;
    int bet;
    double moneyBet;
};
struct APerson{
    std::array<Person, 10> data={};
    int length=0;
};

int position(const APerson& arr, const std::string& str){
    int i=0;
    while(i<arr.length && arr.data[i].name!=str){i++;}
    return i;
}

void readData(APerson& arr){
    std::string str;
    int b, p; double mb;
    std::cout<<"Introduce nombre y apuestas, FIN para terminar: \n";
    std::cout<<"Nombre: "; std::cin>>str;
    while (str!="FIN"){
        std::cout<<"Apuesta (0, 1, 2): ";
        std::cin>>b;
        std::cout<<"Dinero apostado: ";
        std::cin>>mb;
        p=position(arr, str);
        if(p==arr.length && arr.length<10){
            arr.data[arr.length++]=Person{str, b, mb};
        }else{
            arr.data[p].moneyBet+=mb;
        }
        std::cout<<"Nombre: "; std::cin>>str;
    }
}

void printData(const APerson& arr){
    for(int i=0; i<arr.length; i++){
        std::cout<<"Nombre: "<<arr.data[i].name<<", apuesta: "<<arr.data[i].bet<<", dinero apostado: "<<arr.data[i].moneyBet<<".\n";
    }
}

double totalBet(const APerson& arr){
    double sum=0.0;
    for(int i=0; i<arr.length; i++){
        sum+=double(arr.data[i].moneyBet);
    }
    return sum;
}

double correctBet(const APerson& arr, int resultBet){
    double sum=0.0;
    for(int i=0; i<arr.length; i++){
        if(arr.data[i].bet==resultBet){
            sum+=double(arr.data[i].moneyBet);
        }
    }
    return sum;
}

double ratio(const APerson& arr, int resultBet){
    return totalBet(arr)/correctBet(arr, resultBet);
}

void afterResultPartition(APerson& arr, int resultBet){
    double finalBet=totalBet(arr);
    double factor=correctBet(arr, resultBet);
    for(int i=0; i<arr.length; i++){
        if(arr.data[i].bet==resultBet){
            arr.data[i].moneyBet*=double(finalBet/factor);
        }else{
            arr.data[i].moneyBet=0.0;
        }
    }
}

void printEarnings(const APerson& arr){
    for(int i=0; i<arr.length; i++){
        std::cout<<"Nombre: "<<arr.data[i].name<<", dinero ganado: "<<arr.data[i].moneyBet<<".\n";
    }
}



int main(){
    APerson arr;
    readData(arr);
    printData(arr);
    std::cout<<"Introduce el resultado final: ";
    int n;
    std::cin>>n;
    std::cout<<"Apuesta Total: "<<totalBet(arr)<<"\nApuesta acertada: "<<correctBet(arr, n)<<"\nRatio: "<<ratio(arr, n)<<"\n";
    afterResultPartition(arr, n);
    printEarnings(arr);
    return 0;
}