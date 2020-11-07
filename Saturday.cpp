#include "Saturday.h"
#include <iostream>

Saturday::Saturday() {
    bool cont=true;
    int numRaces=5;
    checkDay();
    while (cont && numRaces!=0){
        //run simlations until either tries are depleted or no longer want to race
	    
	    //check if you want to contiune tests

        cout<<"Do you want to do another practice lap? Y/N"<<endl;
        cin>>in;
        if (in==Y){

        }
        else if (in==N){
            cont=false;
        }
        else{cout<<"Incorrect input, continue practice.";
        }
    }
    //call qualify race
}

void Saturday::checkDay() {
	cout<<"Today is Saturday, practice then qualifying."<<endl;
}

void Saturday::handleNextDay(RacingContext* day) {
	//move to sunday
	day->setRacingDay( new Sunday());
}
