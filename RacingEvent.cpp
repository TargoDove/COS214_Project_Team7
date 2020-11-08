#include "RacingEvent.h"

RacingEvent::RacingEvent(string name, Date sDate, RaceTrack *trk)
{
  raceName = name;
  startDate = sDate;
  endDate = sDate;
  endDate.incrementDate(2);
  track = trk;
}

void RacingEvent::RunRace(Date currentDate)
{
  // TODO - implement RacingEvent::RunRace(Date currentDate)
  throw "Not yet implemented";
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
