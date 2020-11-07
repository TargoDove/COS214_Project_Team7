#include "PrizeGiving.h"

PrizeGiving::PrizeGiving() {

    teamWin = finalOrder[0]->getTeamName(); //Name of winners team
    driver1st = finalOrder[0]->getDriver()->getName(); //Name of winners driver
    driver2nd = finalOrder[1]->getDriver()->getName();
    driver3rd = finalOrder[2]->getDriver()->getName();


}

void PrizeGiving::celebrate() {
	cout<<"The National Anthem of "<<teamWin<<" is sung."<<endl;
	cout<<driver1st<<" holds up the trophy."
	cout<<"Everyone celebrates with champagne!"
}

void PrizeGiving::announceWinner() {
    cout<<"The drivers take their places on the podium."<<endl;
    cout<<"The top Team is "<<teamWin<<endl;
    cout<<"_____________________________________________"
    cout<<"In 3rd place we have "<<driver3rd<<endl
    cout<<"In 2nd place we have "<<driver2nd<<endl
    cout<<"In 1st place we have "<<driver1st<<endl
    cout<<"_____________________________________________"
    celebrate();
    cout<<"_____________________________________________"
    cout<<"The drivers are interviewed and then attend a press conference."

}
