#ifndef		__DISPLAY_HH__
#define		__DISPLAY_HH__

#include	<list>
#include        <cstdlib>
#include        <unistd.h>
#include        <SFML/Graphics.hpp>
#include	<SFML/Audio.hpp>
#include	<iostream>
#include	"../../headers/Game.hh"
#include	"../../ILib.hh"

class		Display :	public ILib
{
private:
  sf::RenderWindow		_app;
  sf::Event			_event;
  bool				_isInit;
  sf::Image			*_backgroundImage;
  sf::Sprite			*_backgroundSprite;
  std::list<sf::Sprite *>	_SnakeSpriteList;
  std::list<sf::Sprite *>	_FoodSpriteList;
  std::list<sf::Sprite *>	_HoleSpriteList;
  sf::Music			*_music;
  int				_numFunc;
  int				_snakeSize;
  bool				_isUp;
  bool				_isDown;
  bool				_isRight;
  bool				_isLeft;
  void				(Display::*creation[4])(std::list<ISnake *> &);
public:
  Display();
  ~Display();
  virtual bool			Window() const;
  virtual void			Play(std::list<ISnake *> &sList, std::list<IFood *> &fList, std::list<IHole *> &hlist, int score);
  virtual bool			Init();
  void				Dinit(std::list<ISnake *> &sList, std::list<IFood *> &fList);
  void				setFood(std::list<IFood *> &list);
  void				addSnakeSprite(std::list<ISnake *> &sList);
  void				addElem(int x, int y);
  void				DisplayGame();
  void				Up(std::list<ISnake *> &list);
  void				Down(std::list<ISnake *> &list);
  void				Left(std::list<ISnake *> &list);
  void				Right(std::list<ISnake *> &list);
  void				onOriginalList(std::list<ISnake *> &list, char func);
  void				manageEvent();
  void				setNewCoord(std::list<ISnake *> &list, std::list<IHole *> &hlist);
  bool				checkSpritePresent(const sf::Sprite *sprite, const std::list<IFood *> &list) const;
  void				getNewCoord(const std::list<IFood *> &list, int *x, int *y);
  void				initHole(const std::list<IHole *> &hlist);
  void				Finish();
};

typedef Display *(*maker_Display)();

#endif
