#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<map>
std::vector<int> getLimits(const std::string& code){
    int i=0;
    char c=code[i];
    std::vector<int> lims{0, 0};
    while(c!='-'){
        lims[0]*=10;lims[0]+=(c-'0');
        c=code[++i];
    }
    i++;
    while(i<code.length()){
        lims[1]*=10;lims[1]+=(code[i++]-'0');
    }
    return lims;
}

std::map<int, std::string> getIncorrectPassword(){
    std::ifstream in_file{"./c.txt"};
    if(!in_file){
        return {};
    }
    std::map<int, std::string> ret;
    std::vector<int> lims;
    int count=0;
    int index=0;
    std::string quantity, letter, password;
    while(in_file>>quantity>>letter>>password){
        lims=getLimits(quantity);
        for(char c: password){
            if(c==letter[0]){
                count++;
            }
        }
        if(count<lims[0] || count>lims[1]){
            ret.insert(std::pair(index++, password));
        }
        count=0;
    }
    return ret;
}

int main(){
    auto output=getIncorrectPassword();
    std::cout<<output.at(41)<<"\n";
    return 0;
}