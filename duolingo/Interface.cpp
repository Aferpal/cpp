#include "Interface.h"

Interface::Interface(const Game& game):game{game}{}

void Interface::printResults(){
    system("cls");
    std::cout<<"=======RESULSTADOS DE LA PRUEBA=========\n\n\n";
    std::cout<<"\tNumero de preguntas: "<<game.nQuestions<<"\n\n\tNumero de aciertos: "<<game.correctQuestions<<"\n\n\tPorcentaje de aciertos: "<<std::setprecision(3)<<((float)game.correctQuestions/(float)game.nQuestions)*100.0<<"%\n\n\tPuntos ganados: "<<int(((float)game.correctQuestions/(float)game.nQuestions)*10.0)<<"XP\n\n";
}

void Interface::startGame(){
    char c;
    bool keep=true;
    do{
        system("cls");
        std::cout<<"Playing duolingo right now!\n"<<game.currentQuestion<<"/"<<game.nQuestions<<"\nCurrent right: "<<game.correctQuestions<<"\n";
        printQuestion(game.currentQuestion);
        c=getch();
        processInput(c);
    }while(c!='e' && game.currentQuestion<game.nQuestions);
    printResults();
}
void Interface::processInput(char c){
    switch (c)
    {
    case 80:
        game.questions[game.currentQuestion].changeSelect(QST::DOWN);
        break;
    case 72:
        game.questions[game.currentQuestion].changeSelect(QST::UP);
        break;
    case 13:
        if(game.questions[game.currentQuestion++].isCorrect()){game.correctQuestions++;};
        break;
    default:
        break;
    }
}
void Interface::printOption(const Question& q, int index){
    std::cout<<std::setw(8)<<""<<std::setw(q.options[index-1].size())<<std::setfill('-')<<'\n'<<std::setfill(' ');
    if(index==q.selected){std::cout<<std::setw(7)<<std::right<<"  ==>  ";}else{std::cout<<std::setw(7)<<"";}
    std::cout<<'|'<<q.options[index-1]<<"|\n";
    std::cout<<std::setw(8)<<""<<std::setw(q.options[index-1].size())<<std::setfill('-')<<'\n'<<std::setfill(' ');
}
void Interface::printQuestion(int index){
    std::cout<<std::setw(50)<<std::right<<game.questions[index].question<<'\n';
    for(int i=1; i<=game.questions[i].options.size(); i++){
        printOption(game.questions[index], i);
        std::cout<<'\n';
    }
}
