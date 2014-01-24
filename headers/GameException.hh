//
// GameException.hh for GameException in /home/dell-a_f//projets/nibbler/headers
// 
// Made by florian dell-aiera
// Login   <dell-a_f@epitech.net>
// 
// Started on  Sat Mar 23 13:50:17 2013 florian dell-aiera
// Last update Sat Mar 23 15:18:32 2013 florian dell-aiera
//


#ifndef	__GAMEEXCEPTION_HH__
#define	__GAMEEXCEPTION_HH__

#include <stdexcept>
#include <sstream>
#include <iostream>
#include <string>

class	GameException : public std::exception
{
protected:
  std::string	_msg;
public:
  GameException(const char * Msg);
  virtual	~GameException() throw();
  virtual const char * what() const throw();
};

#endif
