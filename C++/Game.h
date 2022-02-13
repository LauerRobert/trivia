#include <iostream>
#include <list>
#include <vector>

#include "Questionnaire.h"

#ifndef GAME_H_
#define GAME_H_

class Game
{

private:
   std::vector<std::string> players;

   int places[6];
   int purses[6];

   bool inPenaltyBox[6];

   Questionnaire m_questionnaire;

   unsigned int currentPlayer;
   bool isGettingOutOfPenaltyBox;

public:
   Game();
   std::string createRockQuestion(int index);
   bool isPlayable();
   bool add(std::string playerName);

   int howManyPlayers();
   void roll(int roll);

private:
   void askQuestion();
   std::string currentCategory();

public:
   bool wasCorrectlyAnswered();
   bool wrongAnswer();

private:
   bool didPlayerWin();
};

#endif /* GAME_H_ */
