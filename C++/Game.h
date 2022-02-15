#include <vector>

#include "Player.h"
#include "Questionnaire.h"

#ifndef GAME_H_
#define GAME_H_

class Game
{
public:
   Game(int seed = 0);

   bool addPlayer(std::string playerName);
   void play();

   bool m_hasNoWinner;

private:
   void playNextRound();
   bool checkWhetherGameIsPlayable();
   std::string getCurrentPlayersName();
   int rollDie();
   bool checkIfPlayerIsInPenaltyBox(int roll);
   void updatePosition(int roll);
   void askQuestion();
   void answerQuestion();
   void determineNextPlayer();
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
