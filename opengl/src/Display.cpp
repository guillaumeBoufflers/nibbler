//
// Display.cpp for display in /home/dell-a_f//projets/nib/opengl/src
// 
// Made by florian dell-aiera
// Login   <dell-a_f@epitech.net>
// 
// Started on  Tue Mar 19 16:48:46 2013 florian dell-aiera
// Last update Sun Mar 24 18:35:27 2013 maxime sauvage
//

#include	"../headers/Display.hh"
#include	"../../headers/Game.hh"

Display::Display()
{
  this->move_left[0] = &Display::avance; 
  this->move_left[1] = &Display::turnNineLeft;
  this->move_left[2] = &Display::turnOneLeft; 
  this->move_left[3] = &Display::turnTwoLeft;
  this->move_right[0] = &Display::avance; 
  this->move_right[1] = &Display::turnNineRight;
  this->move_right[2] = &Display::turnOneRight; 
  this->move_right[3] = &Display::turnTwoRight;
  this->_angle = 0;
  this->_color = 0;
}

Display::~Display()
{

}

bool	Display::Init()
{
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    return (false);
  SDL_WM_SetCaption("Le nibbler neggaz", NULL);
  if (SDL_SetVideoMode(LWINDOW, HWINDOW, 32, SDL_OPENGL) == NULL)
    return (false);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, LWINDOW,0, HWINDOW);
  return (true);
}

bool	Display::Window() const
{
  return (true);
}

void	Display::Finish()
{
  std::cout << "GAME OVER!!" << std::endl;
}

void	Display::makeCoord(std::list<ISnake *>&sList) const
{
  int	cpt = sList.size();
  std::list<ISnake *>::reverse_iterator it = sList.rbegin();
  std::list<ISnake *>::reverse_iterator it2;

  while (cpt > 1)
    {
      it2 = it;
      it2++;
      (*it)->setX((*it2)->getX());
      (*it)->setY((*it2)->getY());
      it++;
      cpt--;
    }
}

void			Display::avance(std::list<ISnake *>&sList) const
{
  this->makeCoord(sList);
  sList.front()->setX((sList.front()->getX()) - 20);
}

void			Display::turnNineLeft(std::list<ISnake *>&sList) const
{
  this->makeCoord(sList);
  sList.front()->setY((sList.front()->getY()) - 20);
}

void			Display::turnOneLeft(std::list<ISnake *>&sList) const
{
  this->makeCoord(sList);
  sList.front()->setX((sList.front()->getX()) + 20);
}

void			Display::turnTwoLeft(std::list<ISnake *>&sList) const
{
  this->makeCoord(sList);
  sList.front()->setY((sList.front()->getY()) + 20);
}

void			Display::turnNineRight(std::list<ISnake *>&sList) const
{
  this->makeCoord(sList);
  sList.front()->setY((sList.front()->getY()) + 20);
}

void			Display::turnOneRight(std::list<ISnake *>&sList) const
{
  this->makeCoord(sList);
  sList.front()->setX((sList.front()->getX()) + 20);
}

void			Display::turnTwoRight(std::list<ISnake *>&sList) const
{
  this->makeCoord(sList);
  sList.front()->setY((sList.front()->getY()) - 20);
}

void			Display::event(std::list<ISnake *>&sList)
{
  SDL_Event event;

  atexit(SDL_Quit);
  while (SDL_PollEvent(&event))
    { 
      switch(event.type)
  	{
  	case SDL_QUIT:
  	  exit(0);
  	  break;
  	case SDL_KEYDOWN:
  	  switch (event.key.keysym.sym)
  	    {
  	    case SDLK_ESCAPE:
  	      exit(0);
  	      break;
  	    case SDLK_LEFT:
	      this->_angle -= 90;
	      if (this->_angle == (-360))
		this->_angle = 0;
	      break;
  	    case SDLK_RIGHT:
	      this->_angle += 90;
	      if (this->_angle == (360))
		this->_angle = 0;
  	      break;
  	    }
	  break;
  	}
    }
  if (this->_angle <= 0)
    (this->*move_left[(-1) * (this->_angle / 90)])(sList);
  else
    (this->*move_right[this->_angle / 90])(sList);
}

void			Display::makeCarre(double x, double y, int r, int v, int b) const
{
  glColor3ub(r, v, b);
  glVertex2d(-x, -y);
  glVertex2d(-x, y);
  glVertex2d(x, y);
  glVertex2d(x, -y);
}

void			Display::makeSnake(std::list<ISnake *> &sList)
{
  int			i = 0;

  for (std::list<ISnake *>::const_iterator it = sList.begin(); it != sList.end(); it++)
    {
      if (i  == 0)
  	{
  	  glMatrixMode(GL_MODELVIEW);
  	  glLoadIdentity();
	  glTranslatef((*it)->getX() - 10, (*it)->getY() - 10, 0);
  	  glBegin(GL_QUADS);
  	  this->makeCarre(10, 10, 255, 0, 0);
  	  glEnd();
  	}
      else
  	{
	  this->_color = rand() % 255;
  	  glMatrixMode(GL_MODELVIEW);
  	  glLoadIdentity();
	  glTranslatef((*it)->getX() - 10, (*it)->getY() - 10, 0);
  	  glBegin(GL_QUADS);
  	  this->makeCarre(10, 10, 0, this->_color, 0);
  	  glEnd();
  	}
      i++;
    }
}

void			Display::makeFood(std::list<IFood *> &fList) const
{
  for ( std::list<IFood *>::const_iterator it = fList.begin(); it != fList.end(); it++)
    {
      glMatrixMode(GL_MODELVIEW);
      glLoadIdentity();
      glTranslatef((*it)->getX() - 10, (*it)->getY() - 10, 0);
      glBegin(GL_QUADS);
      this->makeCarre(10,10, 0, 0, this->_color);
      glEnd();
      glFlush();
    }
}

void			Display::makeBlackHole(std::list<IHole *> &hList) const
{
  for (std::list<IHole *>::const_iterator it = hList.begin(); it != hList.end(); it++)
    {
      glMatrixMode(GL_MODELVIEW);
      glLoadIdentity();
      glTranslatef((*it)->getX() - 10, (*it)->getY() - 10, 0);
      glBegin(GL_QUADS);
      this->makeCarre(10,10, 0, 0, 0);
      glEnd();
      glFlush();
    }
}

void			Display::see(std::list<ISnake *> &sList, std::list<IFood *> &fList, std::list<IHole *> &hList)
{
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glBegin(GL_QUADS);
  this->makeCarre(LWINDOW , HWINDOW, 240, 240, 240);
  glEnd();
  this->makeSnake(sList);
  this->makeFood(fList);
  this->makeBlackHole(hList);
  glFlush();
  SDL_GL_SwapBuffers();
}

void	Display::Play(std::list<ISnake *> &sList, std::list<IFood *> &fList, std::list<IHole *> &hlist, int score)
{
  score = 0;
  this->see(sList, fList, hlist);
  this->event(sList);
  this->see(sList, fList, hlist);
}

extern "C"
{
  Display		*make_display()
  {
    return new	Display();
  }
}

