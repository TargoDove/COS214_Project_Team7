#include "EngineSim.h"

EngineSim::EngineSim()
{}

EngineSim::~EngineSim()
{}

double EngineSim::simulateComponent(double e)
{
	double bad = 0.2*(pow(e,2));
	double average = 0.4*(pow(e,2));
	double good = 0.6*(pow(e,2))/2;
	double excellent = 0.8*(pow(e,2));

	double simulatedValue = e*(pow(e,2));

	cout << "_______________________________"<<endl;
	cout << "Engine Simulation Complete"<<endl;
	cout << "_______________________________"<<endl;
	cout << "Scored " << simulatedValue << endl;
	if(simulatedValue <= bad)
	{
		cout << "Outcome: [BAD]\ndoes not produce enough power " << endl;
	}
	else if(simulatedValue > bad && simulatedValue < good)
	{
		cout << "Outcome: [AVERAGE]\nsufficient power but unreliable"<< endl;
	}
	else if(simulatedValue >= good && simulatedValue < excellent)
	{
		cout << "Outcome: [GOOD]\nsufficient power is produced"<< endl;
	}
	else if(simulatedValue>= excellent)
	{
		cout << "Outcome: [EXCELLENT]\nThe engine produces excellent power"<< endl;
	}

	cout << "==========SCORE INDEX=========="<<endl;
	cout << "bad:\t\t" << bad << endl;
	cout << "average:\t" << average << endl;
	cout << "good:\t\t" << good << endl;
	cout << "excellent:\t" << excellent << endl;
	cout << "==============================="<<endl;
	return simulatedValue;
}