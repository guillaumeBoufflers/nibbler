#ifndef		__SNAKE_HH__
#define		__SNAKE_HH__

#include	"ISnake.hh"

class		Snake : public ISnake
{
private:
  ISnakeType		_type;
  int			_x;
  int			_y;
public: 
  Snake();
  virtual ~Snake();
  virtual void				addElem(std::list<ISnake *> &list, ISnakeType type, int x, int y)const;
  virtual int				snakeSize(std::list<ISnake *> list) const;
  /******************/
  virtual ISnakeType			getType() const;
  virtual int				getX() const;
  virtual int				getY() const;
  /******************/
  virtual void				setX(int x);
  virtual void			        setY(int y);
  virtual void				setType(ISnakeType type);
};

#endif
