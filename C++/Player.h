class Player
{
public:
   Player(std::string name)
       : m_name(name), m_position(0), m_isInPenaltyBox(false), m_score(0)
   {
   }

   std::string m_name;
   int m_position;
   bool m_isInPenaltyBox;
   int m_score;

private:
};
