#ifndef DRIVER_H
#define DRIVER_H

using namespace std;

class Driver
{
	public:
    Driver();
    Driver(double, double, string);
    ~Driver();
    void addPoints(double);
    double getPoints();
    string getName();
    void clearPoints();
    void addSkill(double);
    double getSkill();
  private:
    double skill;
    double currentPoints;
    string name;
};

#endif
