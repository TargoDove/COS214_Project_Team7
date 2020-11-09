#ifndef DRIVER_H
#define DRIVER_H

#include <string>

using namespace std;

class Driver
{
	public:
    Driver();
    Driver(double, int, string);
    ~Driver();
    void addPoints(int);
    int getPoints();
    string getName();
    void clearPoints();
    void addSkill(double);
    double getSkill();
    
  private:
    double skill;
    int currentPoints;
    string name;
};

#endif
