#ifndef WINDTUNNEL_H
#define WINDTUNNEL_H

#include <cstdlib>

class WindTunnel
{
private:
  int tokens;

public:
  WindTunnel();
  WindTunnel(int);
  virtual ~WindTunnel();
  int getTokens();
  void decrement();
  double testComponent(double);
};

#endif