#include <ctime>
#include <stdlib.h>

#include "Game.h"

void runGame(int seed)
{
   Game aGame(seed);
   bool isWinner{false};

   aGame.addPlayer("Chet");
   aGame.addPlayer("Pat");
   aGame.addPlayer("Sue");

   do
   {
      std::cout << aGame.m_players[aGame.m_currentPlayer] << " is the current player" << std::endl;

      int roll = aGame.roll();

      bool isPlayerOutOfPenaltyBox = !aGame.checkIfPlayerIsInPenaltyBox(roll);
      if (isPlayerOutOfPenaltyBox)
      {
         aGame.updatePosition(roll);
         aGame.m_questionnaire.askQuestion(aGame.currentCategory());
         aGame.answerQuestion();
         isWinner = aGame.didPlayerWin();
      }

      aGame.determineNextPlayer();

   } while (!isWinner);
}

int main(int argc, char *argv[])
{
   for (int i = 1; i < argc; ++i)
   {
      int seed = static_cast<int>(*argv[i] - '0');
      std::cout << "seed: " << seed << '\n';

      runGame(seed);

      std::cout << '\n'
                << '\n';
   }
   std::cout << "argc: " << argc;
}
