#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "Builder.h"
#include "Competition.h"

using namespace std;

class Director 
{
  private: 
  Builder* builder;

public:
  Director(Builder*);
  ~Director();
  void construct();
};

#endif