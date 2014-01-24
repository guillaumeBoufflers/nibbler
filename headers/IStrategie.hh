#ifndef			__ISTRATEGIE_HH__
#define			__ISTRATEGIE_HH__

enum			IStrategieType
  {
    EASY,
    MEDIUM,
    HARD
  };

class			IStrategie
{
public:
  virtual int				getSpeed() const = 0;
  virtual void				setSpeed(int speed) = 0;
  virtual int				getPts() const = 0;
  virtual IStrategieType		getType() const = 0;
  virtual unsigned int			getNbFood() const = 0;
  virtual ~IStrategie(){}
};

#endif
