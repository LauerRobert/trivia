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

   int m_popQuestionIndex;
   int m_scienceQuestionIndex;
   int m_sportsQuestionIndex;
   int m_rockQuestionIndex;
};
