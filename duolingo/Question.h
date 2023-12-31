#pragma once
#include<string>
#include<vector>
namespace QST{
    const int UP=1;
    const int DOWN=0;
}
class Question{
    private:
        int correct;
    public:
        std::string question;
        std::vector<std::string> options;
        int selected=1;
        Question(const std::string& question, const std::vector<std::string>& options, int correct);
        Question(const Question& other);
        bool isCorrect();
        void changeSelect(int );
};