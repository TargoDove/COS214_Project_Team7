#ifndef COMPETITIONBUILDER_H
#define COMPETITIONBUILDER_H

#include "Builder.h"

using namespace std;

class CompetitionBuilder : public Builder
{
private:
  F1Team** teams;
  int numTeams;
  RacingEvent** events;

public:
  CompetitionBuilder();
  ~CompetitionBuilder();
  virtual void buildRacingEvents();
  virtual void buildF1Teams();
  virtual void buildCompetition();
  //F1Team* getPart();
};

#endif