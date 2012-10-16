#include <windows.h>
#include <iostream>
#include "CarFactory.h"



using namespace std;

CarFactory* carFactory;
int factoryFlag = 0;

int main(){
	while(1){
	cin>>factoryFlag;
		if(factoryFlag == 1)
			carFactory = new FordCarFactory;
		else
			carFactory = new RollsCarFactory;
		CarBreak* myBreak = carFactory->CreatCarBreak();
		CarDoor*  myDoor  = carFactory->CreatCarDoor();
		myBreak->Draw();
		myDoor->Draw();
	}
}