#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "Game.h"

Game::Game(int seed) : m_places{}, m_purses{}, m_currentPlayer(0)
{
   srand(seed);
}

bool Game::isPlayable()
{
   return (getPlayerCount() >= 2);
}

bool Game::add(std::string playerName)
{
   m_players.push_back(playerName);
   m_places[getPlayerCount() - 1] = 0;
   m_purses[getPlayerCount() - 1] = 0;
   m_inPenaltyBox[getPlayerCount() - 1] = false;

   std::cout << playerName << " was added" << std::endl;
   std::cout << "They are player number " << getPlayerCount() << std::endl;
   return true;
}

int Game::getPlayerCount()
{
   return m_players.size();
}

bool Game::checkIfPlayerIsInPenaltyBox(int roll)
{
   if (m_inPenaltyBox[m_currentPlayer])
   {
      if (roll % 2 != 0)
      {
         std::cout << m_players[m_currentPlayer] << " is getting out of the penalty box" << std::endl;
         return false;
      }
      else
      {
         std::cout << m_players[m_currentPlayer] << " is not getting out of the penalty box" << std::endl;
         return true;
      }
   }

   return false;
}

int Game::roll()
{
   int roll = rand() % 5 + 1;
   std::cout << "They have rolled a " << roll << std::endl;

   return roll;
}

void Game::updatePosition(int roll)
{
   m_places[m_currentPlayer] = m_places[m_currentPlayer] + roll;
   if (m_places[m_currentPlayer] > 11)
      m_places[m_currentPlayer] = m_places[m_currentPlayer] - 12;

   std::cout << m_players[m_currentPlayer] << "'s new location is " << m_places[m_currentPlayer] << std::endl;
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

void Game::determineNextPlayer()
{
   m_currentPlayer++;
   if (m_currentPlayer == m_players.size())
      m_currentPlayer = 0;
}

bool Game::checkAnswer()
{
   return rand() % 9 != 7;
}

void Game::answerQuestion()
{
   bool isAnswerCorrect = checkAnswer();
   if (isAnswerCorrect)
   {
      handleCorrectAnswer();
   }
   else
   {
      handleWrongAnswer();
   }
}

void Game::handleCorrectAnswer()
{

   m_purses[m_currentPlayer]++;
   std::cout << "Answer was correct!!!!" << std::endl;
   std::cout << m_players[m_currentPlayer]
             << " now has "
             << m_purses[m_currentPlayer]
             << " Gold Coins." << std::endl;
}

void Game::handleWrongAnswer()
{
   std::cout << "Question was incorrectly answered" << std::endl;
   std::cout << m_players[m_currentPlayer] + " was sent to the penalty box" << std::endl;
   m_inPenaltyBox[m_currentPlayer] = true;
}

bool Game::didPlayerWin()
{
   return (m_purses[m_currentPlayer] == 6);
}
