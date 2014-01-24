#ifndef			__STRATEGIE_HH__
#define			__STRATEGIE_HH__

#include		"IStrategie.hh"

namespace		Strategie
{
  class			Easy : public IStrategie
  {
  private:
    IStrategieType	_type;
    int			_speed;
    unsigned int	_nbFood;
    int			_pts;
    
  public:
    virtual IStrategieType		getType() const;
    virtual int		getSpeed() const;
    virtual void	setSpeed(int speed);
    virtual int		getPts() const;
    virtual unsigned int		getNbFood() const ;
    Easy();
    virtual ~Easy();
  };

  class			Medium : public IStrategie
  {
  private:
    IStrategieType	_type;
    int			_speed;
    unsigned int	_nbFood;
    int			_pts;

  public:
    virtual IStrategieType		getType() const;
    virtual int		getSpeed() const;
    virtual void	setSpeed(int speed);
    virtual int		getPts() const;
    virtual unsigned int		getNbFood() const ;
    Medium();
    virtual ~Medium();
  };

  class			Hard : public IStrategie
  {
  private:
    IStrategieType	_type;
    int			_speed;
    unsigned int	_nbFood;
    int			_pts;

  public:
    virtual IStrategieType		getType() const;
    virtual int		getSpeed() const;
    virtual void	setSpeed(int speed);
    virtual int		getPts() const;
    virtual unsigned int		getNbFood() const;
    Hard();
    virtual ~Hard();
  };
}

#endif
