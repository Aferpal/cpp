#include<iostream>
#include<fstream>
#include<string>
#include<vector>

std::string getCode(const std::string& filePath){
    std::ifstream in_file{filePath};
    if(!in_file){
        return "";
    }
    std::string ret;
    in_file>>ret;
    return ret;
}

std::string decodeString(const std::string& code){
    std::string res="";
    int current=0;
    for(auto& c: code){
        switch (c)
        {
        case '#':
            current++;
            break;
        case '@':
            current--;
            break;
        case '*':
            current*=current;
            break;
        case '&':
            res+=char((current+'0'));
            break;
        default:
            break;
        }
    }
    return res;

}   

int main(){
    std::string code= getCode("./code.txt");
    std::cout<<code<<"\n";
    std::string res= decodeString(code);
    std::cout<<res<<"\n";
    return 0;
}