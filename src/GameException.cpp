//
// Exception.cpp for exception in /home/dell-a_f//projets/nibbler/src
// 
// Made by florian dell-aiera
// Login   <dell-a_f@epitech.net>
// 
// Started on  Sat Mar 23 13:47:32 2013 florian dell-aiera
// Last update Sat Mar 23 15:12:59 2013 florian dell-aiera
//

#include	"../headers/GameException.hh"


GameException::GameException(const char * Msg)
{
  std::ostringstream oss;

  oss << Msg;
  this->_msg = oss.str();
}

GameException::~GameException() throw()
{

}


const char	*GameException::what() const throw()
{
  return (this->_msg.c_str());
}
