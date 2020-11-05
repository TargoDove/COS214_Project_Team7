#ifndef DRIVER_H
#define DRIVER_H

using namespace std;

class Driver
{
	public:
    Driver();
    Driver(double, double);
    ~Driver();
    void addPoints(double);
    double getPoints();
    void clearPoints();
    void addSkill(double);
    double getSkill();
  private:
    double skill;
    double currentPoints;
};

#endif