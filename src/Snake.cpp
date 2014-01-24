#include		"../headers/Snake.hh"

Snake::Snake()
{

}

Snake::~Snake()
{

}

/**********************************************/

void				Snake::setX(int x)
{
  this->_x = x;
}

void				Snake::setY(int y)
{
  this->_y = y;
}

void				Snake::setType(ISnakeType type)
{
  this->_type = type;
}

/**********************************************/

ISnakeType			Snake::getType() const
{
  return (this->_type);
}

int				Snake::getX() const
{
  return (this->_x);
}

int				Snake::getY() const
{
  return (this->_y);
}

/**********************************************/

void				Snake::addElem(std::list<ISnake *> &list, ISnakeType type, int x, int y) const
{
  ISnake	*member;

  member = new Snake;
  member->setType(type);
  member->setX(x);
  member->setY(y);
  list.push_front(member);
}

int				Snake::snakeSize(std::list<ISnake *> list) const
{
  return (list.size());
}
