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

	Boost *bst = dynamic_cast<Boost*>(car->getF1Car()->getSpecification("Boost"));
	if (car->getF1Car()->getStrategy()->useBoostStraight() && bst!= 0 && bst->isFull())
	{
		boostVal = bst->getBaseValue();
		bst->useCharge();
	}

	double elTime = straightMultiplier * length / 100;
	double multiplier = 1 + (engineVal*boostVal -1) + ((aerodynamicsVal-1)*length/1000) + (weightVal*speedVal*friction -1);

	elTime /= multiplier;
	elTime *= elementsPerLap;

	*time += elTime;
}
