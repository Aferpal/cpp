// Section 19
// Challenge 2
// Automated Grader
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
struct Student{
    std::string name;
    int rightAnswers;
    Student(std::string, int);
};
Student::Student(std::string name, int rightAnswers): name {name}, rightAnswers{rightAnswers}{}


std::ostream& operator<<(std::ostream& os, const Student& obj){
    os<<std::setw(20)<<std::left<<obj.name<<std::setw(20)<<std::right<<obj.rightAnswers<<"\n";
    return os;
}

void display(std::vector<Student> studentVec){
    int sum=0;
    std::cout<<std::setw(20)<<std::left<<"Student"<<std::setw(20)<<std::right<<"Score"<<"\n----------------------------------------\n";
    for(const Student& student: studentVec){
        sum+=student.rightAnswers;
        std::cout<<student;
    }
    std::cout<<"----------------------------------------\n"<<std::setw(20)<<std::left<<"Average Score"<<std::setw(20)<<std::right<<sum/studentVec.size();
}

int main() {
    std::ifstream in_file{"./responses.txt"};
    if(!in_file){
        std::cout<<"Error trying to open the file\n";
        return 1;
    }
    std::vector<Student> studentVec;
    std::string name;
    std::string response;
    std::string solution;
    in_file>>solution;
    while(in_file>>name>>response){
        int rightAns=0;
        for(size_t i=0; i<response.length(); i++){
            if(response[i]==solution[i]){
                rightAns++;
            }else{
                
            }
        }
        studentVec.push_back(Student{name, rightAns});
    }

    in_file.close();
    display(studentVec);
    return 0;
}

