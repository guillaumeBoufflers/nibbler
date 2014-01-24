#ifndef		__IHOLE_HH__
#define		__IHOLE_HH__

enum		HoleType
  {
    BLACKHOLE
  };

class		IHole
{
public:
  virtual ~IHole(){}
  virtual int	getX() const = 0;
  virtual int	getY() const = 0;
  virtual HoleType	getType() const = 0;
  //
  virtual void	setX(int x) = 0;
  virtual void	setY(int y) = 0;
  //
  virtual void	addElem(std::list<IHole *> &list, int x, int y, HoleType type) = 0;
  virtual void	setType(HoleType type) = 0;
};

#endif
