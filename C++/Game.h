#include <vector>

#include "Player.h"
#include "Questionnaire.h"

#ifndef GAME_H_
#define GAME_H_

class Game
{
public:
   Game(int seed = 0);

   bool addPlayer(const std::string &playerName);
   void play();

   bool m_hasNoWinner;

private:
   void playNextRound();
   bool checkWhetherGameIsPlayable() const;
   std::string getCurrentPlayersName() const;
   int rollDie() const;
   bool checkIfPlayerIsInPenaltyBox(const int &) const;
   void updatePosition(const int &);
   void askQuestion();
   void answerQuestion();
   void determineNextPlayer();
   std::string getNextQuestion(const Category &category);
   bool checkAnswer() const;
   void handleCorrectAnswer();
   void handleWrongAnswer();
   Category getCurrentCategory() const;
   void checkWhetherPlayerWon();
   int getPlayerCount() const;

   std::vector<Player> m_players;
   unsigned int m_currentPlayer;
   Questionnaire m_questionnaire;
};

#endif /* GAME_H_ */
