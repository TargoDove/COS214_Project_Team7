#include "DriverAssistSim.h"

DriverAssistSim::DriverAssistSim()
{}

DriverAssistSim::~DriverAssistSim()
{}

double DriverAssistSim::simulateComponent(double e)
{
	double randomNum = rand() % 1000;
	double bad = 0.2*(randomNum);
	double average = 0.4*(randomNum);
	double good = 0.6*(randomNum) ;
	double excellent = 0.8*(randomNum);

	double simulatedValue = e*(randomNum);
	double improvement = (simulatedValue/excellent)*e;
	cout << "_______________________________"<<endl;
	cout << "Driver assist Simulation Complete"<<endl;
	cout << "_______________________________"<<endl;
	cout << "Scored " << simulatedValue << endl;
	cout << "Improvement " << (improvement)*100 << "%" << endl;
	if(simulatedValue <= bad)
	{
		cout << "Outcome: [BAD]\nDriver assist performs poor on track" << endl;
	}
	else if(simulatedValue > bad && simulatedValue < good)
	{
		cout << "Outcome: [AVERAGE]\nDriver assist perfoms okay on track"<< endl;
	}
	else if(simulatedValue >= good && simulatedValue < excellent)
	{
		cout << "Outcome: [GOOD]\nDriver assist performs good on track"<< endl;
	}
	else if(simulatedValue>= excellent)
	{
		cout << "Outcome: [EXCELLENT]\nDriver assist performs excellent on track"<< endl;
	}

	cout << "==========SCORE INDEX=========="<<endl;
	cout << "bad:\t\t" << bad << endl;
	cout << "average:\t" << average << endl;
	cout << "good:\t\t" << good << endl;
	cout << "excellent:\t" << excellent << endl;
	cout << "==============================="<<endl;
	return improvement*e;
}