#ifndef		__DISPLAY_HH__
#define		__DISPLAY_H__

#include	<list>
#include        <cstdlib>
#include        <unistd.h>
#include	<SDL/SDL.h>
#include	<GL/gl.h>
#include	<GL/glu.h>
#include	<iostream>
#include	"../../headers/Game.hh"
#include	"../../ILib.hh"

class		Display : public ILib
{
private:
  int		_angle;
  int		_color;
  void		(Display::*move_left[4])(std::list<ISnake *> &) const;
  void		(Display::*move_right[4])(std::list<ISnake *> &) const;
public:
  Display();
  ~Display();
  virtual bool	Window() const;
  virtual void	Play(std::list<ISnake *> &sList, std::list<IFood *> &fList, std::list<IHole *> &hlist, int score);
  virtual bool		Init();
  virtual void		Finish();
  void			event(std::list<ISnake *> &sList);
  void			makeCarre(double x, double y, int r, int v, int b) const;
  void			see(std::list<ISnake *> &sList, std::list<IFood *> &fList, std::list<IHole *> &hList);
  void			makeSnake(std::list<ISnake *> &sList);
  void			makeCoord(std::list<ISnake *> &sList) const;
  void			makeFood(std::list<IFood *> &fList) const;
  void			makeBlackHole(std::list<IHole *> &hList) const;
  void			avance(std::list<ISnake *> &sList) const;
  void			turnNineLeft(std::list<ISnake *> &sList) const;
  void			turnOneLeft(std::list<ISnake *> &sList) const;
  void			turnTwoLeft(std::list<ISnake *> &sList) const;
  void			turnNineRight(std::list<ISnake *> &sList) const;
  void			turnOneRight(std::list<ISnake *> &sList) const;
  void			turnTwoRight(std::list<ISnake *> &sList) const;
};

typedef Display	*(*maker_Display)();

#endif
