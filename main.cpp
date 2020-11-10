#include <iostream>
#include <string>
#include "Date.h"
#include "Formula1Date.h"
#include "Director.h"
#include "CompetitionBuilder.h"

using namespace std;

//NOTE:
//int arr[] = {10,20,30,40,50,60};
//int arrSize = sizeof(arr) / sizeof(arr[0]);

int main(int argc, char const *argv[])
{
	//TO DO: Instantiate and initialize all objects
	Date firstDay(1, 1, 2020);
	Formula1Date *f1Date = new Formula1Date(firstDay);
	CompetitionBuilder* builder = new CompetitionBuilder();
	Director * director = new Director(builder);
	director->construct();
	Competition* competition = builder->getPart();

	//TO DO: Register eventObjects with F1Date
	f1Date->registerObj(competition);

	for(int i = 0; i < competition->getNumTeams(); i++)
	{
		f1Date->registerObj(competition->getTeams()[i]);
	}

	//Looping through/simulating year
	for (int i = 0; i < 365; i++)
	{
		f1Date->increment();

		return 0;
	}

	delete f1Date;
	//delete builder;
	delete director;
	delete competition;
}
