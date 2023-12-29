#include<iostream>
#include<string>
#include<vector>
#include<array>
#include<fstream>


bool isCorrectCode(const std::string& str){
    bool cond=false;
    std::array<int, 255> appeared={};
    std::string str1;
    std::string str2;
    int index=0;
    char c=str[index];
    while (c!='-')
    {
        if(appeared[int(c)]==0){
            str1+=c;
        }
        appeared[int(c)]++;
        c=str[++index];
    }
    for(char c:str1){
        if(appeared[int(c)]==1){
            str2+=c;
        }
    }
    index++;
    if((str.size()-index)!=str2.size()){
        return false;
    }
    for(int i=0; i<str2.size(); i++){
        if(str2[i]!=str[index+i]){
            return false;
        }
    }
    return true;
}

std::string getString(const std::string& str){
    int i=1;
    char c=str[0];
    while(c!='-'){
        i++;
    }
    std::string res;
    for(int j=i; j<str.length(); j++){
        res+=str[j];
    }
    return res;
}

std::vector<std::string> getCorrectCodes(){
    std::ifstream in_file{"./c.txt"};
    std::vector<std::string>res;
    std::string str;
    if(!in_file){
        return {};
    }
    while(in_file>>str){
        if(isCorrectCode(str)){
            res.emplace_back(getString(str));
        }
    }
    return res;
    
}

int main(){
    std::vector<std::string> output= getCorrectCodes();
    std::cout<<output.size();
    std::cout<<output[33]<<"\n";
    return 0;
}