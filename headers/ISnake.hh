#ifndef		__ISNAKE_HH__
#define		__ISNAKE_HH__

#include	<list>
#include	<iostream>
#include	<string>

enum		ISnakeType
  {
    HEAD,
    BODY,
    TAIL
  };

class		ISnake
{
public:
  virtual void						addElem(std::list<ISnake *> &list, ISnakeType type, int x, int y) const = 0;
  virtual int						snakeSize(std::list<ISnake *> list) const = 0;
  /****************/
  virtual ISnakeType					getType() const = 0;
  virtual int						getX() const = 0;
  virtual int						getY() const = 0;
  /***************/
  virtual void						setType(ISnakeType type) = 0;
  virtual void						setX(int x) = 0;
  virtual void						setY(int y) = 0;
  virtual ~ISnake(){}
};

#endif
