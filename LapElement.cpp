#include "LapElement.h"

LapElement::LapElement(int num, LapElement *el)
{
	elementsPerLap = num;
	nextElement = el;
}

LapElement::~LapElement()
{
	if(nextElement != NULL)
	{
		delete nextElement;
	}
}

void LapElement::setNextElement(LapElement *el)
{
	if(nextElement == NULL)
	{
		nextElement = el;
	} 
	else 
	{
		el->setNextElement(nextElement);
		nextElement = el;
	}
}
