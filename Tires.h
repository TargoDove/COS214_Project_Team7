#ifndef TIRES_H
#define TIRES_H

using namespace std;

class Tires
{
	public:
    Tires();
    ~Tires();
    virtual double getIntegrity();
    virtual double getSpeed();
    virtual double getDurability();
    virtual void decreaseIntegrity(double) = 0;
    virtual Tires* clone() = 0;

  protected:
    double integrity; //1.0
    double speed;
    double durability;
    Tires(double, double, double);
};

#endif