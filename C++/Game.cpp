#include <iostream>
#include <string>

#include "Game.h"

Game::Game(int seed) : m_currentPlayer(0), m_hasNoWinner(true)
{
   srand(seed);
}

void Game::play()
{
   bool isPlayable = checkWhetherGameIsPlayable();
   if (isPlayable)
   {
      do
      {
         playNextRound();
      } while (m_hasNoWinner);
   }
}

bool Game::checkWhetherGameIsPlayable() const
{
   return (getPlayerCount() >= 2);
}

void Game::playNextRound()
{
   std::cout << getCurrentPlayersName() << " is the current player" << std::endl;

   int dieValue = rollDie();

   bool isFree = !checkIfPlayerIsInPenaltyBox(dieValue);
   if (isFree)
   {
      updatePosition(dieValue);
      askQuestion();
      answerQuestion();
   }

   determineNextPlayer();
}

std::string Game::getCurrentPlayersName() const
{
   return m_players[m_currentPlayer].m_name;
}

bool Game::addPlayer(const std::string &playerName)
{
   m_players.push_back({playerName});

   std::cout << playerName << " was added" << std::endl;
   std::cout << "They are player number " << getPlayerCount() << std::endl;
   return true;
}

int Game::getPlayerCount() const
{
   return m_players.size();
}

bool Game::checkIfPlayerIsInPenaltyBox(const int &dieValue) const
{
   if (m_players[m_currentPlayer].m_isInPenaltyBox)
   {
      if (dieValue % 2 != 0)
      {
         std::cout << m_players[m_currentPlayer].m_name << " is getting out of the penalty box" << std::endl;
         return false;
      }
      else
      {
         std::cout << m_players[m_currentPlayer].m_name << " is not getting out of the penalty box" << std::endl;
         return true;
      }
   }

   return false;
}

int Game::rollDie() const
{
   int dieValue = rand() % 5 + 1;
   std::cout << "They have rolled a " << dieValue << std::endl;

   return dieValue;
}

void Game::updatePosition(const int &dieValue)
{
   m_players[m_currentPlayer].m_position = m_players[m_currentPlayer].m_position + dieValue;
   if (m_players[m_currentPlayer].m_position > 11)
      m_players[m_currentPlayer].m_position = m_players[m_currentPlayer].m_position - 12;

   std::cout << m_players[m_currentPlayer].m_name << "'s new location is " << m_players[m_currentPlayer].m_position << std::endl;
}

void Game::askQuestion()
{
   std::string output = " Question ";
   std::cout << "The category is ";

   Category category = getCurrentCategory();
   switch (category)
   {
   case Category::pop:
      std::cout << "Pop\n";
      output = "Pop" + output + getNextQuestion(Category::pop) + '\n';
      break;
   case Category::science:
      std::cout << "Science\n";
      output = "Science" + output + getNextQuestion(Category::science) + '\n';
      break;
   case Category::sports:
      std::cout << "Sports\n";
      output = "Sports" + output + getNextQuestion(Category::sports) + '\n';
      break;
   case Category::rock:
      std::cout << "Rock\n";
      output = "Rock" + output + getNextQuestion(Category::rock) + '\n';
      break;
   }

   std::cout << output;
}

std::string Game::getNextQuestion(const Category &category)
{
   std::string nextQuestion;
   switch (category)
   {
   case Category::pop:
      nextQuestion = std::to_string(this->m_questionnaire.m_popQuestionIndex++);
      break;
   case Category::science:
      nextQuestion = std::to_string(this->m_questionnaire.m_scienceQuestionIndex++);
      break;
   case Category::sports:
      nextQuestion = std::to_string(this->m_questionnaire.m_sportsQuestionIndex++);
      break;
   case Category::rock:
      nextQuestion = std::to_string(this->m_questionnaire.m_rockQuestionIndex++);
      break;
   }

   return nextQuestion;
}

Category Game::getCurrentCategory() const
{
   switch (m_players[m_currentPlayer].m_position % 4)
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

bool Game::checkAnswer() const
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
   m_players[m_currentPlayer].m_score++;

   checkWhetherPlayerWon();

   std::cout << "Answer was correct!!!!" << std::endl;
   std::cout << m_players[m_currentPlayer].m_name
             << " now has "
             << m_players[m_currentPlayer].m_score
             << " Gold Coins." << std::endl;
}

void Game::handleWrongAnswer()
{
   std::cout << "Question was incorrectly answered" << std::endl;
   std::cout << m_players[m_currentPlayer].m_name + " was sent to the penalty box" << std::endl;
   m_players[m_currentPlayer].m_isInPenaltyBox = true;
}

void Game::checkWhetherPlayerWon()
{
   if (m_players[m_currentPlayer].m_score == 6)
   {
      m_hasNoWinner = false;
   }
}
