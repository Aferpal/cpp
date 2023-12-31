#pragma once
#include "Game.h"
#include<iostream>
#include<iomanip>
#include<conio.h>
class Interface{
    private:
        Game game;
    public:
        Interface(const Game& game);
        void startGame();
        void printQuestion(int index);
        void printOption(const Question& q, int index);
        void processInput(char c);
        void printResults();

};