#include	"../headers/Display.hh"
#include	"../../headers/Game.hh"

Display::Display()
{
  this->_maxheight = HWINDOW / SIDE + 3;
  this->_maxwidth = LWINDOW / SIDE + 2;
  this->_partchar = 'x';
  this->_direction = 'l';
}

bool	Display::Init()
{
  initscr();
  start_color();
  nodelay(stdscr, true);
  keypad(stdscr, true);
  noecho();
  curs_set(0);
  refresh();
  return (true);
}

void    Display::drawWall() const
{
  for (int i=0; i < this->_maxwidth; i++)
    {
      move(0, i);
      addch('-');
    }
  for (int i=0; i < this->_maxheight-3; i++)
    {
      move(i, 0);
      addch('|');
    }
  for (int i=0; i < this->_maxwidth; i++)
    {
      move(i, this->_maxwidth-1);
      addch('|');
    }
  for (int i=0; i < this->_maxwidth; i++)
    {
      move(this->_maxheight-3, i);
      addch('-');
    }
  refresh();
}

bool	Display::Window() const
{
  return (true);
}

void   		Display::dispFood(std::list<IFood *> list) const
{
  for (std::list<IFood *>::const_iterator it = list.begin(); it != list.end(); it++)
    {
      move((*it)->getY()/SIDE, (*it)->getX()/SIDE);
      init_pair(4, COLOR_YELLOW, COLOR_BLACK);
      attron(COLOR_PAIR(4));
      addch('+');
      attroff(COLOR_PAIR(4));
    }
}

void   		Display::dispHole(std::list<IHole *> list) const
{
  for (std::list<IHole *>::const_iterator it = list.begin(); it != list.end(); it++)
    {
      move((*it)->getY()/SIDE, (*it)->getX()/SIDE);
      init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
      attron(COLOR_PAIR(5));
      addch('#');
      attroff(COLOR_PAIR(5));
    }
}

void		Display::movesnake(std::list<ISnake *> &sList, std::list<IFood *> &fList, std::list<IHole *> &hList)
{
  int   tmp = getch();
  ISnake	*s;
  
  this->drawWall();
  this->dispFood(fList);
  this->dispHole(hList);
  switch (tmp)
    {
    case KEY_LEFT:
      if (this->_direction != 'r')
        this->_direction = 'l';
      break;
    case KEY_UP:
      if (this->_direction != 'd')
        this->_direction = 'u';
      break;
    case KEY_DOWN:
      if (this->_direction != 'u')
        this->_direction = 'd';
      break;
    case KEY_RIGHT:
      if (this->_direction != 'l')
        this->_direction = 'r';
      break;
    case 27:
      endwin();
      exit(EXIT_SUCCESS);
      break;
    }
  move((sList.back()->getY())/SIDE, (sList.back()->getX())/SIDE);
  addch(' ');
  refresh();
  s = sList.back();
  sList.pop_back();
  if (this->_direction == 'l')
    {
      s->setX((sList.front()->getX())-SIDE);
      s->setY(sList.front()->getY());
      sList.push_front(s);
    }
  else if (this->_direction == 'r')
    {
      s->setX((sList.front()->getX())+SIDE);
      s->setY(sList.front()->getY());
      sList.push_front(s);
    }
  else if (this->_direction == 'u')
    {
      s->setX(sList.front()->getX());
      s->setY((sList.front()->getY())-SIDE);
      sList.push_front(s);
    }
  else if (this->_direction == 'd')
    {
      s->setX(sList.front()->getX());
      s->setY((sList.front()->getY())+SIDE);
      sList.push_front(s);
    }
  move((sList.front()->getY())/SIDE, (sList.front()->getX())/SIDE);
  init_pair(3, COLOR_BLUE, COLOR_BLACK);
  attron(COLOR_PAIR(3));
  addch(this->_partchar);
  attroff(COLOR_PAIR(3));
  refresh();
}

void    Display::dispScore(int score) const
{
  move(this->_maxheight-2, 0);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
  attron(COLOR_PAIR(2));
  printw("Score: %d", score);
  attroff(COLOR_PAIR(2));  
  refresh();
}

void	Display::Play(std::list<ISnake *> &sList, std::list<IFood *> &fList, std::list<IHole *> &hList, int score)
{
  this->movesnake(sList, fList, hList);
  this->dispScore(score);
}

void	Display::Finish()
{
  move(this->_maxheight/3, this->_maxwidth/3);
  init_pair(1, COLOR_RED, COLOR_BLACK);
  attron(COLOR_PAIR(1));
  printw("GAME OVER");
  attroff(COLOR_PAIR(1));
  move(this->_maxheight/3+3, this->_maxwidth/4);
  printw("Appuyez sur une touche pour quitter");
  refresh();
  nodelay(stdscr, false);
  keypad(stdscr, false);
  getch();
  endwin();
}

Display::~Display()
{

}

extern "C"
{
  Display		*make_display()
  {
    return new	Display();
  }
}
