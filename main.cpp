#include <iostream>
#include <string>
#include "Date.h"
#include "Formula1Date.h"

using namespace std;

//NOTE:
//int arr[] = {10,20,30,40,50,60};
//int arrSize = sizeof(arr) / sizeof(arr[0]);

int main(int argc, char const *argv[])
{
	Date firstDay(1, 1, 2020);
	Formula1Date *f1Date = new Formula1Date(firstDay);

	//TO DO: Instantiate and initialize all objects

	//TO DO: Register eventObjects with F1Date

	//Looping through/simulating year
	for (int i = 0; i < 365; i++)
	{
		f1Date->increment();

		return 0;
	}
