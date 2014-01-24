#ifndef		__Collision_HH__
#define		__Collision_HH__

#include	"../headers/ISnake.hh"
#include	"../headers/IFood.hh"

class		Collision
{
public:
  Collision();
  ~Collision();
  bool		checkSAndS(const std::list<ISnake *> &) const;
  bool		checkSAndF(const std::list<ISnake *> &, std::list<IFood *> &) const;
  bool		checkSAndW(const std::list<ISnake *> &) const;
  int		checkSAndH(const std::list<ISnake *> &, std::list<IHole *> &);
  void		displayCoord(const std::list<ISnake *> &list) const;
};

#endif
