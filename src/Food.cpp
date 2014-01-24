#include		"../headers/Game.hh"

Food::Food()
{
  srand(time(NULL));
}

Food::~Food()
{

}

IFoodType		Food::getType() const
{
  return (this->_type);
}

int			Food::getX() const
{
  return (this->_x);
}

int			Food::getY() const
{
  return (this->_y);
}

/****************/

void			Food::setType(IFoodType type)
{
  this->_type = type;
}

void			Food::setX(int x)
{
  this->_x = x;
}

void			Food::setY(int y)
{
  this->_y = y;
}

void			Food::addElem(std::list<IFood *> &list, const std::list<ISnake *> &slist)
{
  IFood			*member;
  int			x;
  int			y;

  member = new Food();
  x = rand() % LWINDOW;
  while (x % SIDE != 0)
    x = rand() % LWINDOW;
  //  x = LWINDOW - 21;
  if (x < 20 || x > LWINDOW - 20)
    x = 20;
  member->setX(x);
  y = rand() % HWINDOW;
  while (y % SIDE != 0)
    y = rand() % HWINDOW;
  if (y < 20 || y > HWINDOW - 20)
    y = 20;
  member->setY(y);
  list.push_front(member);
}
