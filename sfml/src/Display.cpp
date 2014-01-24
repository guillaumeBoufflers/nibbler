#include	"../headers/Display.hh"
#include	"../../headers/Game.hh"

Display::Display() : _app(sf::VideoMode(LWINDOW, HWINDOW, PIX), "nibbler")
{
  this->_isInit = false;
  this->_numFunc = 3;
  this->_snakeSize = 4;
  this->_isUp = false;
  this->_isDown = false;
  this->_isRight = true;
  this->_isLeft = false;
  this->creation[0] = &Display::Up;
  this->creation[1] = &Display::Down;
  this->creation[2] = &Display::Left;
  this->creation[3] = &Display::Right;
  this->_backgroundSprite = new sf::Sprite();
  this->_backgroundImage = new sf::Image();
  this->_music = new sf::Music();
  if (!this->_music->OpenFromFile("/home/guillaume/Git/nibbler/sounds/murloc.ogg"))
    std::cout << "Impossible de loader le fichier" << std::endl;
  else
    {
      this->_music->Play();
      this->_music->SetVolume(50.0);
    }
}

Display::~Display()
{
  
}

bool			Display::Init()
{  
  return (true);
}

void			Display::onOriginalList(std::list<ISnake *> &list, char func)
{
  ISnake	*tmp;
  int		x;
  int		y;
  
  tmp = list.back();
  list.pop_back();
  x = list.front()->getX();
  y = list.front()->getY();
  if (func == 1)
    y -= 20;
  else if (func == 2)
    y += 20;
  else if (func == 3)
    x -= 20;
  else if (func == 4)
    x += 20;
  tmp->setX(x);
  tmp->setY(y);
  list.push_front(tmp);
}

void	Display::Up(std::list<ISnake *> &list)
{
  sf::Sprite		*newSprite;
  int			x;
  int			y;

  if (this->_isDown == false)
    {
      this->_isUp = true;
      this->_isRight = false;
      this->_isLeft = false;      
      newSprite = this->_SnakeSpriteList.back();
      this->_SnakeSpriteList.pop_back();
      x = this->_SnakeSpriteList.front()->GetPosition().x;
      y = this->_SnakeSpriteList.front()->GetPosition().y;
      y -= 20;
      newSprite->SetPosition(x, y);
      this->_SnakeSpriteList.push_front(newSprite);
      this->onOriginalList(list, 1);
    }
  else
    this->_numFunc = 1;
}

void	Display::Down(std::list<ISnake *> &list)
{
  sf::Sprite		*newSprite;
  int			x;
  int			y;

  if (this->_isUp == false)
    {
      this->_isDown = true;
      this->_isRight = false;
      this->_isLeft = false;
      newSprite = this->_SnakeSpriteList.back();
      this->_SnakeSpriteList.pop_back();
      x = this->_SnakeSpriteList.front()->GetPosition().x;
      y = this->_SnakeSpriteList.front()->GetPosition().y;
      y += 20;
      newSprite->SetPosition(x, y);
      this->_SnakeSpriteList.push_front(newSprite);
      this->onOriginalList(list, 2);
    }
  else
    this->_numFunc = 0;
}

void	Display::Left(std::list<ISnake *> &list)
{
  sf::Sprite		*newSprite;
  int			x;
  int			y;

  if (this->_isRight == false)
    {
      this->_isDown = false;
      this->_isUp = false;
      this->_isLeft = true;
      newSprite = this->_SnakeSpriteList.back();
      this->_SnakeSpriteList.pop_back();
      x = this->_SnakeSpriteList.front()->GetPosition().x;
      y = this->_SnakeSpriteList.front()->GetPosition().y;
      x -= 20;
      newSprite->SetPosition(x, y);
      this->_SnakeSpriteList.push_front(newSprite);
      this->onOriginalList(list, 3);
    }
  else
    this->_numFunc = 3;
}

void	Display::Right(std::list<ISnake *> &list)
{
  sf::Sprite		*newSprite;
  int			x;
  int			y;

  if (this->_isLeft == false)
    {
      this->_isDown = false;
      this->_isUp = false;
      this->_isRight = true;
      newSprite = this->_SnakeSpriteList.back();
      this->_SnakeSpriteList.pop_back();
      x = this->_SnakeSpriteList.front()->GetPosition().x;
      y = this->_SnakeSpriteList.front()->GetPosition().y;
      x += 20;
      newSprite->SetPosition(x, y);
      this->_SnakeSpriteList.push_front(newSprite);
      this->onOriginalList(list, 4);
    }
  else
    this->_numFunc = 2;
}

void			Display::addElem(int x, int y)
{
  std::string		SpriteLocation;
  sf::Sprite		*sprite;
  sf::Image		*image;

  sprite = new sf::Sprite();
  image = new sf::Image();
  SpriteLocation = "/home/guillaume/Git/nibbler/sprite/sun.png";
  if (!image->LoadFromFile(SpriteLocation))
    std::cout<<"Erreur durant le chargement de l'image"<< std::endl;
  sprite->SetImage(*image);
  sprite->Resize(SIDE, SIDE);
  sprite->SetPosition(x, y);
  this->_SnakeSpriteList.push_back(sprite);
}

bool			Display::checkSpritePresent(const sf::Sprite *sprite, const std::list<IFood *> &list) const
{
  for (std::list<IFood *>::const_iterator it = list.begin(); it != list.end(); ++it)
    if (sprite->GetPosition().x == (*it)->getX() && sprite->GetPosition().y == (*it)->getY())
      return (true);
  return (false);
}

void			Display::getNewCoord(const std::list<IFood *> &list, int *x, int *y)
{
  std::list<IFood *>::const_iterator it = list.begin();
  std::list<sf::Sprite *>::const_iterator it2;
  bool		isHere;

  while (it != list.end())
    {
      isHere = false;
      it2 = this->_FoodSpriteList.begin();
      while (it2 != this->_FoodSpriteList.end())
	{
	  if (((*it2)->GetPosition().x == (*it)->getX()) && ((*it2)->GetPosition().y == (*it)->getY()))
	    isHere = true;	  
	  it2++;
	}
      if (isHere == false)
	{
	  (*x) = (*it)->getX();
	  (*y) = (*it)->getY();
	  break;
	}
      it++;
    }
}

void			Display::setFood(std::list<IFood *> &list)
{
  std::string		SpriteLocation;
  sf::Sprite		*sprite;
  sf::Image		*image;
  bool			isHere;
  int			x;
  int			y;

  if (this->_FoodSpriteList.size() == 0)
    {
      for (std::list<IFood *>::const_iterator it = list.begin(); it != list.end(); ++it)
	{
	  sprite = new sf::Sprite();
	  image = new sf::Image();
	  SpriteLocation = "/home/guillaume/Git/nibbler/sprite/sun.png";
	  if (!image->LoadFromFile(SpriteLocation))
	    std::cout<<"Erreur durant le chargement de l'image"<< std::endl;
	  sprite->SetImage(*image);
	  sprite->Resize(SIDE, SIDE);
	  sprite->SetPosition((*it)->getX(), (*it)->getY());
	  this->_FoodSpriteList.push_back(sprite);
	}
    }
  else
    {
      std::list<sf::Sprite *>::iterator it = this->_FoodSpriteList.begin();
      std::list<IFood *>::iterator it2;
      while (it != this->_FoodSpriteList.end())
	{
	  it2 = list.begin();
	  isHere = false;
	  while (it2 != list.end())
	    {
	      if (((*it)->GetPosition().x == (*it2)->getX()) && ((*it)->GetPosition().y == (*it2)->getY()))
		isHere = true;
	      it2++;
	    }
	  if (isHere == false)
	    {	      
	      this->getNewCoord(list, &x, &y);
	      (*it)->SetPosition(x, y);
	    }
	  it++;
	}
    }
}

void		Display::initHole(const std::list<IHole *> &hlist)
{
  sf::Sprite		*sprite;
  sf::Image		*image;
  
  for (std::list<IHole *>::const_iterator it = hlist.begin(); it != hlist.end(); ++it)
    {
      sprite = new sf::Sprite();
      image = new sf::Image();
      if (!image->LoadFromFile("/home/guillaume/Git/nibbler/sprite/capsule.png"))
	std::cout<<"Erreur durant le chargement de l'image"<< std::endl;
      sprite->SetImage(*image);
      sprite->Resize(SIDE, SIDE);
      sprite->SetPosition((*it)->getX(), (*it)->getY());
      this->_HoleSpriteList.push_back(sprite);
    }
}

void	       	Display::Play(std::list<ISnake *> &sList, std::list<IFood *> &fList, std::list<IHole *> &hlist, int score)
{
  if (this->_isInit == false)
    {
      this->Dinit(sList, fList);
      this->initHole(hlist);
    }
  if (sList.size() != this->_snakeSize)
    this->addSnakeSprite(sList);
  this->manageEvent();
  (this->*creation[this->_numFunc])(sList);
  this->setNewCoord(sList, hlist);
  this->setFood(fList);
  this->DisplayGame();
  this->_app.Clear();
}

void			Display::DisplayGame()
{
  //  this->_app.Draw(*this->_backgroundSprite);
  for (std::list<sf::Sprite *>::const_iterator it = this->_SnakeSpriteList.begin(); it != this->_SnakeSpriteList.end(); ++it)
    this->_app.Draw(**it);
  for (std::list<sf::Sprite *>::const_iterator it = this->_FoodSpriteList.begin(); it != this->_FoodSpriteList.end(); ++it)
    this->_app.Draw(**it);
  for (std::list<sf::Sprite *>::const_iterator it = this->_HoleSpriteList.begin(); it != this->_HoleSpriteList.end(); ++it)
    this->_app.Draw(**it);
  this->_app.Display();
}

void			Display::Dinit(std::list<ISnake *> &sList, std::list<IFood *> &fList)
{
  this->_isInit = true;
  for (std::list<ISnake *>::const_iterator it = sList.begin(); it != sList.end(); ++it)
    this->addElem((*it)->getX(), (*it)->getY());  
}

bool			Display::Window() const
{
  return (this->_app.IsOpened());
}

void			Display::manageEvent()
{
  while (this->_app.GetEvent(this->_event))
    {
      if (this->_event.Type == sf::Event::Closed)
	this->_app.Close();
      if (this->_event.Type == sf::Event::KeyPressed)
	{
	  if (this->_event.Key.Code == sf::Key::Escape)
	    this->_app.Close();
	  else if (this->_event.Key.Code == sf::Key::Up)
	    this->_numFunc = 0;
	  else if (this->_event.Key.Code == sf::Key::Down)
	    this->_numFunc = 1;
	  else if (this->_event.Key.Code == sf::Key::Left)
	    this->_numFunc = 2;
	  else if (this->_event.Key.Code == sf::Key::Right)
	    this->_numFunc = 3;
	}
    }
}

void			Display::addSnakeSprite(std::list<ISnake *> &sList)
{
  ISnake	*back;
  back = sList.back();
  this->addElem(back->getX(), back->getY());
  this->_snakeSize += 1;
}

void			Display::setNewCoord(std::list<ISnake *> &list, std::list<IHole *> &hlist)
{
  std::list<ISnake *>::iterator it2;
  std::list<IHole *>::iterator it3;

  it2 = list.begin();
  for (std::list<sf::Sprite *>::iterator it = this->_SnakeSpriteList.begin(); it != this->_SnakeSpriteList.end(); ++it, ++it2)
    (*it)->SetPosition((*it2)->getX(), (*it2)->getY());
  it3 = hlist.begin();
  for (std::list<sf::Sprite *>::iterator it = this->_HoleSpriteList.begin(); it != this->_HoleSpriteList.end(); ++it, ++it3)
    (*it)->SetPosition((*it3)->getX(), (*it3)->getY());
}

void			Display::Finish()
{
  delete(this->_music);
}

extern "C"
{
  Display		*make_display()
  {
    return new	Display();
  }
}
