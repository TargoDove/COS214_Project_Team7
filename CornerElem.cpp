#include "CornerElem.h"

CornerElem::CornerElem(int num, LapElement *next, double s, double f) : LapElement(num, next)
{
	cornerMultiplier = 5.0;
	sharpness = s; //Should ideally be 0.5 to 2
	friction = f; //Should be between 1.0 and 4.0
}

void CornerElem::handleLap(AssembledCar *car, double *time)
{
	//numLaps
	//straightMultiplier, sharpness, friction
	//Tires(actualspeed), boost, aerodynamics, weight, breakefficiency
	F1Car * f1car = car->getF1Car();
	double speedVal = f1car->getTires()->getActualSpeed();
	double boostVal = 1.0;
	double weightVal = (f1car->getSpecification("Weight")->getBaseValue() / 1000.0);
	//double breakVal = (f1car->getSpecification("BreakEfficiency")->getBaseValue());
	double overtakeTime = 0.0;//15.0

	Boost *bst = dynamic_cast<Boost *>(f1car->getSpecification("Boost"));
	if (f1car->getStrategy()->useBoostCorner(f1car->getTires()) && bst != 0 && bst->isFull())
	{
		boostVal = bst->getBaseValue();
		bst->useCharge();

		double rNum = (((double)rand() * 1.0) / RAND_MAX);
		double chance = 0.1*boostVal;
		if(chance > 1.0) chance = 1.0;

		if(rNum > 1.0-chance) overtakeTime = 15.0;
		
	}

	double burstPenalty = 0.0;

	double elTime = cornerMultiplier * sharpness;
	double divider = 1 + (weightVal * weightVal -1) + (speedVal * friction - 1);

	//If tire integrity is below 20% they should burst
	f1car->getTires()->decreaseIntegrity(0.0045*elementsPerLap);

	if(f1car->getTires()->getIntegrity() < 0.2)//Penalty for burst tires
	{
		double chance = (f1car->getTires()->getIntegrity()-0.1) *10;
		double rNum = (((double)rand() * 1.0) / RAND_MAX);

		if (rNum > chance) //burst occured
		{
			burstPenalty = 60.0;
		}
	}

	elTime /= divider;
	elTime *= elementsPerLap;
	elTime -= 15.0;
	elTime += burstPenalty;

	*time += elTime;
}
