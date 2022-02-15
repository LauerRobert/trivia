#include <iostream>
#include <string>

#include "Game.h"

void runGame(int seed)
{
   Game aGame(seed);

   aGame.addPlayer("Chet");
   aGame.addPlayer("Pat");
   aGame.addPlayer("Sue");

   aGame.play();
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
