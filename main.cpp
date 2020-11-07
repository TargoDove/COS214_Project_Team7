#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	Formula1Date *F1Date = new Formula1Date("1 January 2020");

	//TO DO: Instantiate and initialize all objects

	//TO DO: Register eventObjects with F1Date

	//Looping through/simulating year
	for (int i = 0; i < 365; i++)
	{
		F1Date->increment();

		return 0;
	}
