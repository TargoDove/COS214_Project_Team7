#ifndef BOOST_H
#define BOOST_H

#include "F1CarSpecification.h"

using namespace std;

class Boost : public F1CarSpecification
{
private:
  double charge; //Between 0 and 1

public:
  Boost();
  Boost(double);
  bool isFull();
  void addCharge(double);
  void useCharge();
};

#endif