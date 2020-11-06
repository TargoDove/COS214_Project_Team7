//Paulus Wilhelmus Mouton u18069704
#include <iostream>
using namespace std;
int main()
{
    class Container
    {
        private:
            bool ArrivalStatus;
            bool destination;
            string* toolList;
            string Car; //CHANGE
            int dayCount;
            int GarageIndex;
            string ContainerType;
        public:
            Container(bool dest, string* tools, int teamId){
                ArrivalStatus = false;
                dayCount = 0;
                GarageIndex = teamId;
                destination = dest;
                toolList = tools;
                ContainerType = "tools";
                cout << "A container to transport the tools is being prepared" << "\n";
            }

            Container(bool dest, string LeCar, int teamId){ //CHANGE
                ArrivalStatus = false;
                dayCount = 0;
                destination = dest;
                Car = LeCar;
                ContainerType = "car";
                cout << "Transport for the F1 car is being prepared" << "\n";
            }

            bool getStatus(){
                return ArrivalStatus;
            }

            void setStatus(bool status){
                ArrivalStatus = status;
            }

            string* getContents(){
                return toolList;
            }

            void setContents(string tools[4]){
                toolList = tools;
            }

            bool getDestination(){
                return destination;
            }

            void setDestination(bool dest){
                destination = dest;
            }

            void increaseCount(){
                dayCount++;
            }

            int getDayCount(){
                return dayCount;
            }

            string getContainerType(){
                return ContainerType;
            }
    };
/*
//////////////////////////////////////////////////////////////////////////////////////////////////
//MAIN FOR TESTING//
/////////////////////////////////////////////////////////////////////////////////////////////////

    string toolList[4] = {"Spenna", "Hemma", "Screwyoudriva", "Rrrrench"};
    Container toolContainer(true, toolList, 1);
    Container carContainer(true, "Ferrari", 2);
    cout << toolContainer.getContainerType() << "\n";
    cout << carContainer.getContainerType() << "\n";

	*/return 0;
}
