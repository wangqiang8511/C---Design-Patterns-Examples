#include "CarFactory.h"

void FordCarBreak::Draw(){
	cout<<"I am a car break of Ford! \n";
}

void FordCarDoor::Draw(){
	cout<<"I am a car door of Ford! \n";
}

void RollsCarBreak::Draw(){
	cout<<"I am a car break of Rollys-Royce! \n";
}

void RollsCarDoor::Draw(){
	cout<<"I am a car door of Rollys-Royce! \n";
}

FordCarBreak* FordCarFactory::CreatCarBreak(){
	return new FordCarBreak;
}

FordCarDoor* FordCarFactory::CreatCarDoor(){
	return new FordCarDoor;
}

RollsCarBreak* RollsCarFactory::CreatCarBreak(){
	return new RollsCarBreak;
}

RollsCarDoor* RollsCarFactory::CreatCarDoor(){
	return new RollsCarDoor;
}