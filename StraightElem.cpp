#include "StraightElem.h"

StraightElem::StraightElem(int num, LapElement *next, double l, double f) : LapElement(num, next)
{
	straightMultiplier = 10.0; 
	length = l;	//Should ideally be 100 to 200
	friction = f;
}

void StraightElem::handleLap(AssembledCar *car, double *time)
{
	//numLaps
	//straightMultiplier, length, friction
	//Tires(actualspeed), boost, aerodynamics, weight, breakefficiency
	double speedVal = car->getF1Car()->getTires()->getActualSpeed();
	double boostVal = 1.0;
	double engineVal = (car->getF1Car()->getSpecification("EnginePower")->getBaseValue() / 200.0);
	double aerodynamicsVal = (car->getF1Car()->getSpecification("Aerodynamics")->getBaseValue()/100.0);
	double weightVal = (car->getF1Car()->getSpecification("Weight")->getBaseValue() / 1000.0);
	double breakVal = (car->getF1Car()->getSpecification("BreakEfficiency")->getBaseValue());

	if (car->getF1Car()->getStrategy()->useBoostStraight() && car->getF1Car()->getSpecification("Boost")->isFull())
	{
		F1CarSpecification * bst = car->getF1Car()->getSpecification("Boost");
		boostVal = bst->getBaseValue();
		bst->useBoost();
	}

	double elTime = straightMultiplier * l / 100;
	double multiplier = 1 + (engineVal*boostVal -1) + ((aerodynamics-1)*length/1000) + (weightVal*speedVal*friction -1);

	elTime /= multiplier;
	elTime *= elementsPerLap;

	*time += elTime;
}
