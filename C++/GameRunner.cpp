#include <iostream>
#include <string>

#include "Game.h"

void runGame(int seed)
{
   Game aGame(seed);

   aGame.addPlayer("Chet");
   aGame.addPlayer("Pat");
   aGame.addPlayer("Sue");

   bool isPlayable = aGame.checkWhetherGameIsPlayable();
   if (isPlayable)
   {
      do
      {
         std::cout << aGame.getCurrentPlayersName() << " is the current player" << std::endl;

         int roll = aGame.roll();

         bool isFree = !aGame.checkIfPlayerIsInPenaltyBox(roll);
         if (isFree)
         {
            aGame.updatePosition(roll);
            aGame.askQuestion();
            aGame.answerQuestion();
         }

         aGame.determineNextPlayer();

      } while (aGame.m_hasNoWinner);
   }
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
