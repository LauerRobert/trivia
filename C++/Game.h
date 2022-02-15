#include <iostream>
#include <list>
#include <vector>

#include "Questionnaire.h"

#ifndef GAME_H_
#define GAME_H_

class Game
{
public:
   std::vector<std::string> m_players;
   unsigned int m_currentPlayer;

   int m_places[6];
   int m_purses[6];

   bool m_inPenaltyBox[6];

   Questionnaire m_questionnaire;

   bool m_isGettingOutOfPenaltyBox;

public:
   Game(int seed);

   bool isPlayable();
   bool addPlayer(std::string playerName);
   std::string getCurrentPlayersName();
   int getPlayerCount();

   int roll();
   bool checkIfPlayerIsInPenaltyBox(int roll);
   void askQuestion(Category category);
   bool checkAnswer();

   void answerQuestion();
   void handleCorrectAnswer();
   void handleWrongAnswer();

   void determineNextPlayer();
   void updatePosition(int roll);
   Category currentCategory();
   bool didPlayerWin();
};

#endif /* GAME_H_ */
