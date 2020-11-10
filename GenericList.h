#ifndef GENERICLIST_H
#define GENERICLIST_H

#include <string>
#include "Iterator.h"
#include "F1CarSpecification.h"
#include "EngineeringDepartments.h"

using namespace std;

template <class T>
class GenericList
{
public:
  GenericList();
  ~GenericList();
  virtual void addItem(T *);
  virtual void removeItem(string);
  virtual void removeItem(int);
  virtual T *getItem(string);
  virtual T *getItem(int);
  virtual Iterator *createIterator();
  virtual bool isEmpty();
  virtual int size();

protected:
  T **array;
  int numItems;
};

#endif