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
       : popQuestionIndex(0), scienceQuestionIndex(0), sportsQuestionIndex(0), rockQuestionIndex(0)
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
         output = "Pop" + output + std::to_string(this->popQuestionIndex++) + '\n';
         break;
      case Category::science:
         output = "Science" + output + std::to_string(this->scienceQuestionIndex++) + '\n';
         break;
      case Category::sports:
         output = "Sports" + output + std::to_string(this->sportsQuestionIndex++) + '\n';
         break;
      case Category::rock:
         output = "Rock" + output + std::to_string(this->rockQuestionIndex++) + '\n';
         break;
      }

      std::cout << output;
   }

   int popQuestionIndex;
   int scienceQuestionIndex;
   int sportsQuestionIndex;
   int rockQuestionIndex;
};
