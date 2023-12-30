#include<fstream>
#include<iostream>
#include<conio.h>

const int MAX_SIZE=1024;
std::ostream& operator<<(std::ostream& os, const char* str){
    while(*str!='\0'){
        std::cout<<*(str++);
    }
    return os;
}
int strlen(char* str){
    int s=0;
    while(*(str+(s++))!='\0'){}
    return (s-1);
}

void strcpy(char* dst, char* src){
    while(*src!='\0'){
        *(dst++)=*(src++);
    }
}

int readFile(char* buffer, int size, std::ifstream* in_file){
    char temp[2]={0};
    int currentSize=0;
    if(!in_file){
        return -1;
    }
    while(in_file->get(*temp) && currentSize<=size){
        strcpy(buffer, temp);
        buffer+=(strlen(temp));
        currentSize+=strlen(temp);
    }
    return 0;
}
int saveFile(char* buffer, std::ofstream* file){
    std::string str=buffer;
    *file<<str;
    return 0;
}



int main(int argc, char** argv){
    char* filePath=argv[1];
    system("cls");
    system("color 3");
    std::ifstream in_file{filePath};
    char body[MAX_SIZE]={0};
    if(readFile(body, MAX_SIZE, &in_file)<0){
        std::cout<<"(Unexisting file. Creating a new one)\n";
    }
    std::cout<<"\n\n\t\tWELCOME TO THE TEXT EDITOR: \n\n";
    std::cout<<body;
    char c=getch();
    while(c!=27 && strlen(body)<MAX_SIZE){   
        if(c==13){*(body+strlen(body))='\n';std::cout<<'\n';}else if(c==8){if(strlen(body)>0){*(body+strlen(body)-1)='\0'; system("cls"); std::cout<<body;}}else{
            *(body+strlen(body))=c;
            std::cout<<c;
        }
        c=getch();
    }
    in_file.close();
    std::ofstream o_file{filePath};
    saveFile(body, &o_file);
    o_file.close();
    system("color 7");
    system("cls");
    return 0;
}