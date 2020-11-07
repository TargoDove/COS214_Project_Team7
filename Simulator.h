#ifndef SIMULATOR_H
#define SIMULATOR_H
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Simulator
{
	public:
		virtual double simulateComponent(double e) = 0;
		virtual ~Simulator(){}
};
#endif