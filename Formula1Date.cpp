#include "Formula1Date.h"

Formula1Date::Formula1Date(Date d)
{
  date = d;
}

Formula1Date::~Formula1Date()
{
  while(!eventObjs.empty()){
    delete eventObjs.back();
    eventObjs.pop_back();
  }
}

void Formula1Date::increment()
{
  date++;
}

bool Formula1Date::registerObj(EventObject * obj)
{
  eventObjs.push_back(obj);
}

bool Formula1Date::deregisterObj(EventObject * obj)
{
  list<EventObject *>::iterator it = std::find(eventObjs.begin(), eventObjs.end(), obj);
  if (it != eventObjs.end())
  {
    eventObjs.remove(obj);
    return true;
  }
  return false;
}

Date Formula1Date::getDate()
{
  return date;
}

void Formula1Date::setDate(Date d)
{
  date = d;
}
