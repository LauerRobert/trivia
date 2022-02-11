#include <ctime>
#include <stdlib.h>

#include "Game.h"

static bool notAWinner;

void runGame(int seed)
{
   srand(seed);
   Game aGame;

   aGame.add("Chet");
   aGame.add("Pat");
   aGame.add("Sue");

   do
   {

      aGame.roll(rand() % 5 + 1);

      if (rand() % 9 == 7)
      {
         notAWinner = aGame.wrongAnswer();
      }
      else
      {
         notAWinner = aGame.wasCorrectlyAnswered();
      }
   } while (notAWinner);
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
