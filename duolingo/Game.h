#pragma once
#include"Question.h"
class Game{
    private:
        
    public:
        std::vector<Question> questions;
        int nQuestions;
        int currentQuestion=0;
        int correctQuestions=0;
        Game(const std::vector<Question>& questions);
};

