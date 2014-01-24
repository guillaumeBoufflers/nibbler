#include		"../headers/Game.hh"

Hole::Hole()
{

}

Hole::~Hole()
{

}

int	Hole::getX() const
{
  return (this->_x);
}

int	Hole::getY() const
{
  return (this->_y);
}

void	Hole::setX(int x)
{
  this->_x = x;
}

void	Hole::setType(HoleType type)
{
  this->_type = type;
}

void	Hole::setY(int y)
{
  this->_y = y;
}

void	Hole::addElem(std::list<IHole *> &list, int x, int y, HoleType type)
{
  IHole	*member;

  member = new Hole();
  member->setX(x);
  member->setY(y);
  member->setType(type);
  list.push_front(member);
}

HoleType	Hole::getType() const
{
  return (this->_type);
}
