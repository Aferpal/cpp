#include<iostream>
#include<string>
#include<array>
const int MAX=20;
struct TArray{
    std::array<std::string, MAX> data;
    int length;
};
bool has(const TArray& arr, const std::string& str){
    int i=0; 
    while(i<arr.length && arr.data[i++]!=str){}
    return i!=(arr.length);
}
int getAsciiSum(const std::string& str){
    int sum=0;
    for(const char& c:str){
        sum+=(c-'\0');
    }
    return sum;
}
void readText(TArray& res){
    res.data={}; res.length=0;
    std::cout<<"Introduzca una cadena de texto con fin para terminar: ";
    std::string str;
    std::string first;
    std::cin>>first;
    std::cin>>str;
    while (str!="FIN")
    {
        if(!has(res, str) && (getAsciiSum(str)<=getAsciiSum(first))){
            res.data[res.length++]=str;
        }
        std::cin>>str;
    }
}
void swap(TArray& arr, int i1, int i2){
    auto aux=arr.data[i1];
    arr.data[i1]=arr.data[i2];
    arr.data[i2]=aux;
}
int getPivot(TArray& arr, int start, int end){
    auto pivot=arr.data[start];
    int pIndex=start;
    for(int i=start+1; i<=end; i++){
        if(arr.data[i]<=arr.data[start]){pIndex++;}
    }
    swap(arr, start, pIndex);
    int i=start, j=end;
    while((i<pIndex) && (j>pIndex)){
        while(arr.data[i]<=arr.data[pIndex]){
            i++;
        }
        while(arr.data[j]>arr.data[pIndex]){
            j--;
        }
        if((i<pIndex) && (j>pIndex)){
            swap(arr, i++, j--);
        }
    }
    return pIndex;
}
void quicksort(TArray& arr, int start, int end){
    if(start>=end){
        return;
    }
    int pivotIndex=getPivot(arr, start, end);
    quicksort(arr, start, pivotIndex-1);
    quicksort(arr, pivotIndex+1, end);
}


int main(){
    TArray arr;
    readText(arr);
    quicksort(arr, 0, arr.length-1);
    for(int i=0; i<arr.length; i++){
        std::cout<<arr.data[i]<<" ";
        }
    std::cout<<'\n';
    return 0;
}