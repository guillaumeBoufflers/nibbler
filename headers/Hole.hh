#ifndef		__HOLE_HH__
#define		__HOLE_HH__

#include	"IHole.hh"

class	Hole : public IHole
{
private:
  int		_x;
  int		_y;
  HoleType	_type;
public:
  Hole();
  virtual ~Hole();
  //
  virtual int		getX() const;
  virtual int		getY() const;
  //
  virtual void		setX(int x);
  virtual void		setY(int y);
  //
  virtual void		addElem(std::list<IHole *> &list, int x, int y, HoleType type);
  virtual HoleType	getType() const;
  virtual void		setType(HoleType type);
};

#endif
