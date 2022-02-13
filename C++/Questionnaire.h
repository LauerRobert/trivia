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
   {
      for (int i = 0; i < 50; i++)
      {
         std::ostringstream oss(std::ostringstream::out);
         oss << "Pop Question " << i;

         popQuestions.push_back(oss.str());

         char str[255];
         sprintf(str, "Science Question %d", i);
         scienceQuestions.push_back(str);

         char str1[255];
         sprintf(str1, "Sports Question %d", i);
         sportsQuestions.push_back(str1);

         rockQuestions.push_back(createRockQuestion(i));
      }
   }

   std::string createRockQuestion(int index)
   {
      char indexStr[127];
      sprintf(indexStr, "Rock Question %d", index);
      return indexStr;
   }

   std::list<std::string> popQuestions;
   std::list<std::string> scienceQuestions;
   std::list<std::string> sportsQuestions;
   std::list<std::string> rockQuestions;
};
