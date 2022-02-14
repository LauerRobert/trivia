#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "Game.h"

Game::Game() : places{}, purses{}, currentPlayer(0)
{
}

bool Game::isPlayable()
{
   return (howManyPlayers() >= 2);
}

bool Game::add(std::string playerName)
{
   players.push_back(playerName);
   places[howManyPlayers()] = 0;
   purses[howManyPlayers()] = 0;
   inPenaltyBox[howManyPlayers()] = false;

   std::cout << playerName << " was added" << std::endl;
   std::cout << "They are player number " << players.size() << std::endl;
   return true;
}

int Game::howManyPlayers()
{
   return players.size();
}

std::string categoryToString(Category category)
{
   switch (category)
   {
   case Category::pop:
      return "Pop";
   case Category::rock:
      return "Rock";
   case Category::science:
      return "Science";
   case Category::sports:
      return "Sports";
   }
}

void Game::roll(int roll)
{
   std::cout << players[currentPlayer] << " is the current player" << std::endl;
   std::cout << "They have rolled a " << roll << std::endl;

   if (inPenaltyBox[currentPlayer])
   {
      if (roll % 2 != 0)
      {
         isGettingOutOfPenaltyBox = true;

         std::cout << players[currentPlayer] << " is getting out of the penalty box" << std::endl;
         places[currentPlayer] = places[currentPlayer] + roll;
         if (places[currentPlayer] > 11)
            places[currentPlayer] = places[currentPlayer] - 12;

         std::cout << players[currentPlayer] << "'s new location is " << places[currentPlayer] << std::endl;
         std::cout << "The category is " << categoryToString(currentCategory()) << std::endl;
         this->m_questionnaire.askQuestion(currentCategory());
      }
      else
      {
         std::cout << players[currentPlayer] << " is not getting out of the penalty box" << std::endl;
         isGettingOutOfPenaltyBox = false;
      }
   }
   else
   {

      places[currentPlayer] = places[currentPlayer] + roll;
      if (places[currentPlayer] > 11)
         places[currentPlayer] = places[currentPlayer] - 12;

      std::cout << players[currentPlayer] << "'s new location is " << places[currentPlayer] << std::endl;
      std::cout << "The category is " << categoryToString(currentCategory()) << std::endl;
      this->m_questionnaire.askQuestion(currentCategory());
   }
}

Category Game::currentCategory()
{
   switch (places[currentPlayer] % 4)
   {
   case 0:
      return Category::pop;
   case 1:
      return Category::science;
   case 2:
      return Category::sports;
   case 3:
      return Category::rock;
   }
}

bool Game::wasCorrectlyAnswered()
{
   if (inPenaltyBox[currentPlayer])
   {
      if (isGettingOutOfPenaltyBox)
      {
         std::cout << "Answer was correct!!!!" << std::endl;
         purses[currentPlayer]++;
         std::cout << players[currentPlayer]
                   << " now has "
                   << purses[currentPlayer]
                   << " Gold Coins." << std::endl;

         bool winner = didPlayerWin();
         currentPlayer++;
         if (currentPlayer == players.size())
            currentPlayer = 0;

         return winner;
      }
      else
      {
         currentPlayer++;
         if (currentPlayer == players.size())
            currentPlayer = 0;
         return true;
      }
   }
   else
   {

      std::cout << "Answer was corrent!!!!" << std::endl;
      purses[currentPlayer]++;
      std::cout << players[currentPlayer]
                << " now has "
                << purses[currentPlayer]
                << " Gold Coins." << std::endl;

      bool winner = didPlayerWin();
      currentPlayer++;
      if (currentPlayer == players.size())
         currentPlayer = 0;

      return winner;
   }
}

bool Game::wrongAnswer()
{
   std::cout << "Question was incorrectly answered" << std::endl;
   std::cout << players[currentPlayer] + " was sent to the penalty box" << std::endl;
   inPenaltyBox[currentPlayer] = true;

   currentPlayer++;
   if (currentPlayer == players.size())
      currentPlayer = 0;
   return true;
}

bool Game::didPlayerWin()
{
   return !(purses[currentPlayer] == 6);
}
