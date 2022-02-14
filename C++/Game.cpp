#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "Game.h"

Game::Game() : m_places{}, m_purses{}, m_currentPlayer(0)
{
}

bool Game::isPlayable()
{
   return (getPlayerCount() >= 2);
}

bool Game::add(std::string playerName)
{
   m_players.push_back(playerName);
   m_places[getPlayerCount()] = 0;
   m_purses[getPlayerCount()] = 0;
   m_inPenaltyBox[getPlayerCount()] = false;

   std::cout << playerName << " was added" << std::endl;
   std::cout << "They are player number " << m_players.size() << std::endl;
   return true;
}

int Game::getPlayerCount()
{
   return m_players.size();
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
   std::cout << m_players[m_currentPlayer] << " is the current player" << std::endl;
   std::cout << "They have rolled a " << roll << std::endl;

   if (m_inPenaltyBox[m_currentPlayer])
   {
      if (roll % 2 != 0)
      {
         m_isGettingOutOfPenaltyBox = true;

         std::cout << m_players[m_currentPlayer] << " is getting out of the penalty box" << std::endl;
         m_places[m_currentPlayer] = m_places[m_currentPlayer] + roll;
         if (m_places[m_currentPlayer] > 11)
            m_places[m_currentPlayer] = m_places[m_currentPlayer] - 12;

         std::cout << m_players[m_currentPlayer] << "'s new location is " << m_places[m_currentPlayer] << std::endl;
         std::cout << "The category is " << categoryToString(currentCategory()) << std::endl;
         this->m_questionnaire.askQuestion(currentCategory());
      }
      else
      {
         std::cout << m_players[m_currentPlayer] << " is not getting out of the penalty box" << std::endl;
         m_isGettingOutOfPenaltyBox = false;
      }
   }
   else
   {

      m_places[m_currentPlayer] = m_places[m_currentPlayer] + roll;
      if (m_places[m_currentPlayer] > 11)
         m_places[m_currentPlayer] = m_places[m_currentPlayer] - 12;

      std::cout << m_players[m_currentPlayer] << "'s new location is " << m_places[m_currentPlayer] << std::endl;
      std::cout << "The category is " << categoryToString(currentCategory()) << std::endl;
      this->m_questionnaire.askQuestion(currentCategory());
   }
}

Category Game::currentCategory()
{
   switch (m_places[m_currentPlayer] % 4)
   {
   case 0:
      return Category::pop;
   case 1:
      return Category::science;
   case 2:
      return Category::sports;
   case 3:
      return Category::rock;
   default:
      throw "invalid category";
   }
}

bool Game::wasCorrectlyAnswered()
{
   if (m_inPenaltyBox[m_currentPlayer])
   {
      if (m_isGettingOutOfPenaltyBox)
      {
         std::cout << "Answer was correct!!!!" << std::endl;
         m_purses[m_currentPlayer]++;
         std::cout << m_players[m_currentPlayer]
                   << " now has "
                   << m_purses[m_currentPlayer]
                   << " Gold Coins." << std::endl;

         bool winner = didPlayerWin();

         determineNextPlayer();
         return winner;
      }
      else
      {
         determineNextPlayer();
         return true;
      }
   }
   else
   {

      std::cout << "Answer was corrent!!!!" << std::endl;
      m_purses[m_currentPlayer]++;
      std::cout << m_players[m_currentPlayer]
                << " now has "
                << m_purses[m_currentPlayer]
                << " Gold Coins." << std::endl;

      bool winner = didPlayerWin();

      determineNextPlayer();

      return winner;
   }
}

void Game::determineNextPlayer()
{
   m_currentPlayer++;
   if (m_currentPlayer == m_players.size())
      m_currentPlayer = 0;
}

bool Game::wrongAnswer()
{
   std::cout << "Question was incorrectly answered" << std::endl;
   std::cout << m_players[m_currentPlayer] + " was sent to the penalty box" << std::endl;
   m_inPenaltyBox[m_currentPlayer] = true;

   determineNextPlayer();

   return true;
}

bool Game::didPlayerWin()
{
   return !(m_purses[m_currentPlayer] == 6);
}
