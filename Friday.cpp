#include "Friday.h"
#include <iostream>

Friday::Friday() {
    bool cont=true;
    int numRaces=5;
    checkDay();
    char in;
    while (cont && numRaces!=0){
        //run simlations until either tries are depleted or no longer want to race

        cout<<"Do you want to do another practice lap? Y/N"<<endl;
        cin>>in;
        if (in){

        }
        else if (!in){
            cont=false;
        }
        else{cout<<"Incorrect input, continue practice.";
        }
    }
}

void Friday::checkDay() {
	cout<<"Today is Friday, Practice Day."<<endl;
}

void Friday::handleNextDay(RacingDay* day) {
    day->setRacingDay( new Saturday());
}
