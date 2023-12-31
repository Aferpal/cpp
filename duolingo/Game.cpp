#include "Game.h"


Game::Game(const std::vector<Question>& questions):questions{questions}{
    nQuestions=questions.size();
}