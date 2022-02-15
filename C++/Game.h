#include <vector>

#include "Player.h"
#include "Questionnaire.h"

#ifndef GAME_H_
#define GAME_H_

class Game
{
public:
   Game(int seed);

   bool checkWhetherGameIsPlayable();
   bool addPlayer(std::string playerName);
   std::string getCurrentPlayersName();
   int roll();
   bool checkIfPlayerIsInPenaltyBox(int roll);
   void updatePosition(int roll);
   void askQuestion();
   void answerQuestion();
   void determineNextPlayer();

   bool m_hasNoWinner;

private:
   std::string getNextQuestion(Category category);
   bool checkAnswer();
   void handleCorrectAnswer();
   void handleWrongAnswer();
   Category currentCategory();
   void checkWhetherPlayerWon();
   int getPlayerCount();

   std::vector<Player> m_players;
   unsigned int m_currentPlayer;
   Questionnaire m_questionnaire;
};

#endif /* GAME_H_ */
