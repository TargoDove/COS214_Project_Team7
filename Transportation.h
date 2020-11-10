#ifndef TRANSPORTATION_H
#define TRANSPORTATION_H

#include "Container.h"
#include <string>
#include <iostream>

using namespace std;

class Transportation
{
protected:
  Container *container;

public:
  virtual ~Transportation();
  void Transport(Container *c);
  void loadContainer(Container *c);
  Container *unloadContainer();
  Container* returnCars();
  virtual void sendContainer() = 0;
};

class Ship : public Transportation
{
public:
  Ship(Container* c);
  virtual void sendContainer();
};

class Truck : public Transportation
{
public:
  Truck(Container *c);
  virtual void sendContainer();
};

class Plane : public Transportation
{
public:
  Plane(Container *c);
  void sendContainer();
};
#endif