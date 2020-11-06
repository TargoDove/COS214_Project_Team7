#ifndef CONCRETEITERATOR_H
#define CONCRETEITERATOR_H

#include "Iterator.h"
#include "F1CarSpecification.h"
#include "EngineeringDepartments.h"

using namespace std;

template <class T>
class ConcreteIterator : public Iterator
{
	public:
    ConcreteIterator(T **);
    ~ConcreteIterator();
    void first();
    void next();
    bool hasNext();
    int current();
    T* getCurrent();
  
  protected:
    int currentPosition;
    T** array;
};

#endif