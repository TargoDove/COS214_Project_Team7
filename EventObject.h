#ifndef EVENTOBJECT_H
#define EVENTOBJECT_H

#include "Date.h"

using namespace std;

class EventObject
{
	public:
    EventObject();
    virtual ~EventObject();
    virtual void update(Date) = 0;
};

#endif
