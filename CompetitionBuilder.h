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
  int numRacingEvents;
  Competition* comp;
  void addDepartments(F1Team *);
  double randNumGen();
  void addSpecifications(F1Car*);

public:
  CompetitionBuilder();
  ~CompetitionBuilder();
  virtual void buildRacingEvents();
  virtual void buildF1Teams();
  virtual void buildCompetition();
  Competition *getPart();
};

#endif