#ifndef FORMULA1DATE_H
#define FORMULA1DATE_H

#include "Date.h"
#include "EventObject.h"
#include <list>

using namespace std;

class Formula1Date
{
	public:
    Formula1Date(Date);
    ~Formula1Date();
    void increment();
    bool registerObj(EventObject*);
    bool deregisterObj(EventObject *);
    Date getDate();
    void setDate();

  private:
    Date date;
    list<EventObject *> eventObjs;
};

#endif
