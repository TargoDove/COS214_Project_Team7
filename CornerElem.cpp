#include "CornerElem.h"

CornerElem::CornerElem(int num, LapElement *next, double s, double f) : LapElement(num, next)
{
	cornerMultiplier = 5.0;
	sharpness = s; //Should ideally be 100 to 200
	friction = f;
}

void CornerElem::handleLap(AssembledCar *car, double *time)
{
	//numLaps
	//straightMultiplier, sharpness, friction
	//Tires(actualspeed), boost, aerodynamics, weight, breakefficiency
	double speedVal = car->getF1Car()->getTires()->getActualSpeed();
	double boostVal = 1.0;
	double weightVal = (car->getF1Car()->getSpecification("Weight")->getBaseValue() / 1000.0);
	double breakVal = (car->getF1Car()->getSpecification("BreakEfficiency")->getBaseValue());

	if (car->getF1Car()->getStrategy()->useBoostCorner() && car->getF1Car()->getSpecification("Boost")->isFull())
	{
		F1CarSpecification *bst = car->getF1Car()->getSpecification("Boost");
		boostVal = bst->getBaseValue();
		bst->useBoost();
	}

	// TODO - implement CornerElem::handleLap
	throw "Not yet finished";

	// double elTime = straightMultiplier * l / 100;
	// double multiplier = 1 + (engineVal * boostVal - 1) + ((aerodynamics - 1) * length / 1000) + (weightVal * speedVal * friction - 1);

	// elTime /= multiplier;
	// elTime *= elementsPerLap;

	// *time += elTime;
}
