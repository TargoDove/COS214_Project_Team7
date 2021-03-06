#include "RacingEvent.h"

RacingEvent::RacingEvent(string name, Date sDate, RaceTrack *trk)
{
  raceName = name;
  startDate = sDate;
  if (startDate.getDayOfWeek() != 5) //5 -> Friday
  {
    startDate.incrementDate(5 - startDate.getDayOfWeek());
  }
  endDate = sDate;
  endDate.incrementDate(2);
  track = trk;
  dayState = new Friday(this);
}

RacingEvent::~RacingEvent()
{
  
  if(dayState != NULL)
  {
    delete dayState;
    dayState = NULL;
  }

  if(track != NULL)
  {
    delete track;
    track = NULL;
  }
}

void RacingEvent::runRace(Date currentDate)
{
  if (dayState != NULL)
  {
    dayState->handle(currentDate);
  }
}

RaceTrack *RacingEvent::getRaceTrack()
{
  return track;
}

Date RacingEvent::getStartDate()
{
  return startDate;
}

Date RacingEvent::getEndDate()
{
  return endDate;
}
string RacingEvent::getName()
{
  return raceName;
}

void RacingEvent::setState(RacingDay* state){
  dayState = state;
}
