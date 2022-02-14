#include <sstream>

enum Category
{
   pop = 0,
   science,
   sports,
   rock
};

class Questionnaire
{
public:
   Questionnaire()
       : m_popQuestionIndex(0), m_scienceQuestionIndex(0), m_sportsQuestionIndex(0), m_rockQuestionIndex(0)
   {
   }

   std::string createQuestion(int index)
   {
      char indexStr[127];
      sprintf(indexStr, "Rock Question %d", index);
      return indexStr;
   }

   void askQuestion(Category category)
   {
      std::string output = " Question ";

      switch (category)
      {
      case Category::pop:
         output = "Pop" + output + std::to_string(this->m_popQuestionIndex++) + '\n';
         break;
      case Category::science:
         output = "Science" + output + std::to_string(this->m_scienceQuestionIndex++) + '\n';
         break;
      case Category::sports:
         output = "Sports" + output + std::to_string(this->m_sportsQuestionIndex++) + '\n';
         break;
      case Category::rock:
         output = "Rock" + output + std::to_string(this->m_rockQuestionIndex++) + '\n';
         break;
      }

      std::cout << output;
   }

   int m_popQuestionIndex;
   int m_scienceQuestionIndex;
   int m_sportsQuestionIndex;
   int m_rockQuestionIndex;
};
