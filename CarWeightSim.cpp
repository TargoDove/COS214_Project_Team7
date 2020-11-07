#include"CarWeightSim.h"

CarWeightSim::CarWeightSim()
{}

CarWeightSim::~CarWeightSim()
{}

double CarWeightSim::simulateComponent(double e)
{
	double maxSpeed = 100 + (rand() % (376 - 100 + 1));
	double bad = 0.2*(pow(e,2)*sqrt(maxSpeed));
	double average = 0.4*(pow(e,2)*sqrt(maxSpeed));
	double good = 0.6*(pow(e,2)*sqrt(maxSpeed));
	double excellent = 0.8*(pow(e,2)*sqrt(maxSpeed));


	double simulatedValue = e*(pow(e,2)*sqrt(maxSpeed));
	double improvement = (simulatedValue/excellent)*(e/2);
	cout << "_______________________________"<<endl;
	cout << "Car weight Simulation Complete"<<endl;
	cout << "_______________________________"<<endl;
	cout << "Scored " << simulatedValue << endl;
	cout << "Improvement " << (improvement)*100 << "%" << endl;
	if(simulatedValue <= bad)
	{
		cout << "Outcome: [BAD]\nweak structural integrity " << endl;
	}
	else if(simulatedValue > bad && simulatedValue < good)
	{
		cout << "Outcome: [AVERAGE]\nThe car weight is just right"<< endl;
	}
	else if(simulatedValue >= good && simulatedValue < excellent)
	{
		cout << "Outcome: [GOOD]\nGood car weight"<< endl;
	}
	else if(simulatedValue>= excellent)
	{
		cout << "Outcome: [EXCELLENT]\nPerfect car weight"<< endl;
	}

	cout << "==========SCORE INDEX=========="<<endl;
	cout << "bad:\t\t" << bad << endl;
	cout << "average:\t" << average << endl;
	cout << "good:\t\t" << good << endl;
	cout << "excellent:\t" << excellent << endl;
	cout << "==============================="<<endl;
	return improvement*e;
}	