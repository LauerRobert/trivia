#include <vector>

#include "Player.h"
#include "Questionnaire.h"

#ifndef GAME_H_
#define GAME_H_

class Game
{
public:
   std::vector<Player> m_players;
   unsigned int m_currentPlayer;

   Questionnaire m_questionnaire;

   bool m_isGettingOutOfPenaltyBox;

   bool m_hasNoWinner;

public:
   Game(int seed);

   bool checkWhetherGameIsPlayable();
   bool addPlayer(std::string playerName);
   std::string getCurrentPlayersName();
   int getPlayerCount();

   int roll();
   bool checkIfPlayerIsInPenaltyBox(int roll);
   void askQuestion();
   std::string getNextQuestion(Category category);
   bool checkAnswer();

   void answerQuestion();
   void handleCorrectAnswer();
   void handleWrongAnswer();

   void determineNextPlayer();
   void updatePosition(int roll);
   Category currentCategory();
   void checkWhetherPlayerWon();

private:
};

#endif /* GAME_H_ */
