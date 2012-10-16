#include <windows.h>
#include <iostream>
#include "CarBuilder.h"
using namespace std;

int main(){
	Car* myCar1;
	FordCarBuilder myFordCarBuilder;
	myCar1 = CarMaker::MakeCar(myFordCarBuilder);
	myCar1->carBreak->Draw();
	myCar1->carDoor->Draw();
	Car* myCar2;
	RollsCarBuilder myRollsCarBuilder;
	myCar2 = CarMaker::MakeCar(myRollsCarBuilder);
	myCar2->carBreak->Draw();
	myCar2->carDoor->Draw();
	while(1);
}