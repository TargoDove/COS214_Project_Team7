#include "PracticeTrack.h"
PracticeTrack::PracticeTrack(){
    bestScore=0;
    worstScore=0;
    currentScore=0;
    cout<<"Ready to practice!"<<endl;
}
//need to make sure it instantiates with each test car
void PracticeTrack::simulateTrack(F1Car* testCar, RaceTrack* track) {
    //will add up all scores to a total of 100
    int totalScore=0;


	//test tyres on track
	if (track.getPercentStr()<track.getPercentCor()){
        //checks if tires are soft
        if(testcar->fittedTires->type=="soft"){totalScore+=30;}
        if(testcar->fittedTires->type=="medium"){totalScore+=20;}
        if(testcar->fittedTires->type=="hard"){totalScore+=10;}

	}
	else if (track.getPercentStr()>track.getPercentCor()){
        //checks if tires are soft
        if(testcar->fittedTires->type=="soft"){totalScore+=10;}
        if(testcar->fittedTires->type=="medium"){totalScore+=20;}
        if(testcar->fittedTires->type=="hard"){totalScore+=30;}

	}
	else if (track.getPercentStr()==track.getPercentCor()){
        //checks if tires are soft
        if(testcar->fittedTires->type=="soft"){totalScore+=20;}
        if(testcar->fittedTires->type=="medium"){totalScore+=30;}
        if(testcar->fittedTires->type=="hard"){totalScore+=20;}
	}


	//Weather check
    if (track.checkWeather()=="wet"){
        //checks if tires are soft
        if(testcar->fittedTires->type=="soft"){totalScore+=30;}
        if(testcar->fittedTires->type=="medium"){totalScore+=20;}
        if(testcar->fittedTires->type=="hard"){totalScore+=10;}

    }
    else if (track.checkWeather()=="Dry"){
        //checks if tires are hard
        if(testcar->fittedTires->type=="soft"){totalScore+=20;}
        if(testcar->fittedTires->type=="medium"){totalScore+=20;}
        if(testcar->fittedTires->type=="hard"){totalScore+=30;}

    }
    else if (track.checkWeather()=="Temperate"){
        //checks if tires are medium
        if(testcar->fittedTires->type=="soft"){totalScore+=20;}
        if(testcar->fittedTires->type=="medium"){totalScore+=30;}
        if(testcar->fittedTires->type=="hard"){totalScore+=20;}
    }

    //need to add the points for aerodynamics + weight + engine for a maximum score of 40
    //it will then be added to the total score and returned
    if (bestScore==0 && worstScore==0 && currentScore==0){
        bestScore = totalScore;
        worstScore = totalScore;
        currentScore = totalScore;
    }
    if (totalScore>bestScore){
        bestScore=totalScore;
        cout<<"New Best Score"<<endl;
    }
    if (totalScore<WorstScore){
        bestScore=totalScore;
        cout<<"New Worst Score"<<endl;
    }

    currentScore=totalScore;

    cout<<"Best: "<<bestScore<<endl;
    cout<<"Worst: "<<worstScore<<endl;
    cout<<"Current: "<<currentScore<<endl;

}
