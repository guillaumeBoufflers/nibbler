#ifndef		__IFOOD_HH__
#define		__IFOOD_HH__

#include	<list>
#include	<iostream>
#include	<string>

enum		IFoodType
  {
    CAKE,
    POISON,
    POWER
  };

class		IFood
{
public:
  virtual void				addElem(std::list<IFood *> &list, const std::list<ISnake *> &slist) = 0;
  virtual IFoodType			getType() const = 0;
  virtual void				setType(IFoodType type) = 0;
  virtual int				getX() const = 0;
  virtual int				getY() const = 0;
  virtual void				setX(int x) = 0;
  virtual void				setY(int y) = 0;
  virtual ~IFood(){}
};

#endif
