class Player
{
public:
   Player(std::string name)
      : m_isInPenaltyBox(false), m_position(0), m_score(0), m_name(name)
   {}

   bool m_isInPenaltyBox;
   int m_position;
   int m_score;
   std::string m_name;

private:
};
