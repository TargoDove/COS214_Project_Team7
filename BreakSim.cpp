#include "BreakSim.h"

BreakSim::BreakSim()
{}

BreakSim::~BreakSim()
{}

double BreakSim::simulateComponent(double e)
{
	double bad = 0.2*(e*1000*9.8);
	double average = 0.4*(e*1000*9.8);
	double good = 0.6*(e*1000*9.8);
	double excellent = 0.8*(e*1000*9.8);

	double simulatedValue = e*(e*1000*9.8);
	cout << "_______________________________"<<endl;
	cout << "Breaks Simulation Complete"<<endl;
	cout << "_______________________________"<<endl;
	cout << "Scored " << simulatedValue << endl;
	if(simulatedValue <= bad)
	{
		cout << "Outcome: [BAD]\nThe car takes long to stop"<< endl;
	}
	else if(simulatedValue > bad && simulatedValue < good)
	{
		cout << "Outcome: [AVERAGE]\nAverage break performance "<< endl;
	}
	else if(simulatedValue >= good && simulatedValue < excellent)
	{
		cout << "Outcome: [GOOD]\nThe car stops just a the right time "<< endl;
	}
	else if(simulatedValue>= excellent)
	{
		cout << "Outcome: [EXCELLENT]\nThe car stops at will"<< endl;
	}

	cout << "==========SCORE INDEX=========="<<endl;
	cout << "bad:\t\t" << bad << endl;
	cout << "average:\t" << average << endl;
	cout << "good:\t\t" << good << endl;
	cout << "excellent:\t" << excellent << endl;
	cout << "==============================="<<endl;
	return simulatedValue;
}
