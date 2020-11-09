#include "AeroSim.h"
#include <ctime>
#include <random>

AeroSim::AeroSim()
{}

AeroSim::~AeroSim()
{}

double AeroSim::simulateComponent(double e)
{
	srand(time(0));
	double maxSpeed = 100 + (rand() % (376 - 100 + 1));
	double bad = 0.2*(pow(maxSpeed,2))/2;
	double average = 0.4*(pow(maxSpeed,2))/2;
	double good = 0.6*(pow(maxSpeed,2))/2;
	double excellent = 0.8*(pow(maxSpeed,2))/2;
	
	double simulatedValue = e*(pow(maxSpeed,2))/2;
	//double improvement = (simulatedValue/excellent)*e;
	improvement = (((double)rand() * 1.0) / RAND_MAX); //This will give a random value from 0-1
	cout << "_______________________________"<<endl;
	cout << "Aerodynamics Simulation Complete"<<endl;
	cout << "_______________________________"<<endl;
	cout << "Scored " << simulatedValue << endl;
	cout << "Improvement " << (improvement)*100 << "%" << endl;
	if(simulatedValue <= bad)
	{
		cout << "Outcome: [BAD]\ncar will likely experience lift at " << maxSpeed <<"KM/h"<< endl;
	}
	else if(simulatedValue > bad && simulatedValue < good)
	{
		cout << "Outcome: [AVERAGE]\nLift is possible at " << maxSpeed <<"KM/h"<< endl;
	}
	else if(simulatedValue >= good && simulatedValue < excellent)
	{
		cout << "Outcome: [GOOD]\nLift is less likey at " << maxSpeed <<"KM/h"<< endl;
	}
	else if(simulatedValue>= excellent)
	{
		cout << "Outcome: [EXCELLENT]\nLift is not possible at " << maxSpeed <<"KM/h"<< endl;
	}

	cout << "==========SCORE INDEX=========="<<endl;
	cout << "bad:\t\t" << bad << endl;
	cout << "average:\t" << average << endl;
	cout << "good:\t\t" << good << endl;
	cout << "excellent:\t" << excellent << endl;
	cout << "==============================="<<endl;
	return improvement*e;
}