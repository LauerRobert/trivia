#include <iostream>
#include <list>
#include <vector>

#include "Questionnaire.h"

#ifndef GAME_H_
#define GAME_H_

class Game
{

private:
   std::vector<std::string> m_players;

   int m_places[6];
   int m_purses[6];

   bool m_inPenaltyBox[6];

   Questionnaire m_questionnaire;

   unsigned int m_currentPlayer;
   bool m_isGettingOutOfPenaltyBox;

public:
   Game();

   bool isPlayable();
   bool add(std::string playerName);
   int getPlayerCount();
   void roll(int roll);

   bool wasCorrectlyAnswered();
   bool wrongAnswer();

private:
   void determineNextPlayer();
   Category currentCategory();
   bool didPlayerWin();
};

#endif /* GAME_H_ */
