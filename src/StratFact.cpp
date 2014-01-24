#include	"../headers/StratFact.hh"

StratFact::StratFact()

{  initTab();
}

StratFact::~StratFact()
{

}

void	StratFact::initTab()
{
  this->creation[0] = &StratFact::newEasy;
  this->creation[1] = &StratFact::newMedium;
  this->creation[2] = &StratFact::newHard;
}

IStrategie	*StratFact::newEasy() const
{
  return (new Strategie::Easy());
}

IStrategie	*StratFact::newMedium() const
{
  return (new  Strategie::Medium);
}

IStrategie	*StratFact::newHard() const
{
  return (new  Strategie::Hard);
}

IStrategie	*StratFact::create(IStrategieType type) const
{
  if (type >= 0 && type <= 2)
    return ((this->*creation[type])());
  return NULL;
}
