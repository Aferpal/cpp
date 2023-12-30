#include<iostream>
#include<vector>
#include<string>



/*void encryptWord(const std::string& word){
    std::vector<std::vector<int>> binary;
    std::vector<int> digitBin;
    int ascii;
    int i=0;
    for(char c:word){
        binary.push_back({});
        digitBin={};
        ascii=c-'\0';
        while(ascii>0 || digitBin.size()<8){
            if(ascii>0){
                digitBin.push_back(ascii%2);
                ascii/=2;
            }else{
                digitBin.push_back(0);
            }
        }
        for(int j=digitBin.size()-1; j>=0; j--){
            binary[i].push_back(digitBin[j]);
        }
        i++;
    }
    for(const auto& n:binary){
        for(const auto& v: n){
            std::cout<<v;
        }
        std::cout<<" ";
    }
    std::cout<<"\n\nDECRYPT\n";
    std::string message="";
    
    for(const auto& n:binary){
        ascii=0;
        for(int j=0; j<n.size(); j++){
            ascii*=2; ascii+=n[j];
        }
        message+=char(ascii);
    }
    std::cout<<message<<"\n";

}*/
void encryptWord(char* word, int* binary){
    const int SIZE=8;
    int currentSize=0;
    int ascii;
    int i=0;
    while(word[i]!='\0'){
        ascii=*(word+(i++))-'\0';
        if(currentSize<=1016){
            binary+=SIZE;
            currentSize+=SIZE;
            for(int j=0; j<SIZE; j++){
                *(binary-j)=(ascii%2);
                ascii/=2;
            }
        }
    }
    binary-=currentSize;
    *(binary)=currentSize;
}

void decryptBinary(int* binary, char* str){
    int size=*binary;
    int ascii=0;
    binary++;
    for(int i=0; i<(size/8); i++){
        for(int j=0; j<8; j++){
            ascii*=2; ascii+=*(binary++);
            
        }
        *(str++)=char(ascii);
        ascii=0;
    };
    str-=size/8;
    binary-=(size+1);
}



int main(int argc, char** argv){
    char* str=argv[1];
    int binary[1024]={0};
    std::cout<<"Binary code: ";
    encryptWord(str, binary);
    for(int i=0; i<*binary; i++){
        if((i%8)==0 && i!=0){std::cout<<' ';}
        std::cout<<*(binary+i+1);
    }
    std::cout<<'\n'<<"Original word decrypted: ";
    decryptBinary(binary, str);
    while(*(str)!='\0'){
        std::cout<<*(str++);
    }
    std::cout<<'\n';
    return 0;
}