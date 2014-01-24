#ifndef		__STRATFACT_H__
#define		__STRATFACT_H__

#include	<cstdio>
#include	<cstdlib>
#include	"Strategie.hh"

class		StratFact
{
private:
  IStrategie	*newEasy() const;
  IStrategie	*newMedium() const;
  IStrategie	*newHard() const;
  IStrategie	*(StratFact::*creation[3])() const;
public:
  StratFact();
  ~StratFact();
  void		initTab();
  IStrategie	*create(IStrategieType type) const;
};

#endif
