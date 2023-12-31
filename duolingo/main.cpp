#include<iostream>
#include<string>
#include<vector>
#include "Interface.h"



int main(){
	Question q1("How do you say strong in German?", {"Leute", "Stark", "Erwwaschene"}, 2);
	Question q2("What port is currently used for https?", {"443", "80", "404"}, 1);
	Question q3("What does it mean 'Sehr' in German?", {"loud", "sir", "very"}, 3);
	Game game({q1, q2, q3});
	Interface interface{game};
	interface.startGame();
	return 0;
}