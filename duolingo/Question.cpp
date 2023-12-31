#include "Question.h"

Question::Question(const std::string& question, const std::vector<std::string>& options, int correct):question{question}, options{options}, correct{correct}{}
Question::Question(const Question& other):question{other.question}, options{other.options}, correct{other.correct}{}
bool Question::isCorrect(){return this->selected==this->correct;}
void Question::changeSelect(int dir){
    if(dir==1){
        if(selected==1){selected=3;}else{selected--;}
    }else{
        if(selected==options.size()){selected=1;}else{selected++;}
    }
}