#include "CarBuilder.h"

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

Car::Car(){
	carBreak = 0;
	carDoor = 0;
}

Car* CarMaker::MakeCar(CarBuilder &builder){
	builder.CreatCar();
	builder.CreatCarBreak();
	builder.CreatCarDoor();
	return builder.GetCar();
}

CarBuilder::CarBuilder(){}

FordCarBuilder::FordCarBuilder(){
	myCar = 0;
}

void FordCarBuilder::CreatCar(){
	myCar = new Car;
}

void FordCarBuilder::CreatCarBreak(){
	FordCarBreak* myBreak = new FordCarBreak;
	myCar->carBreak = myBreak;
}

void FordCarBuilder::CreatCarDoor(){
	FordCarDoor* myDoor = new FordCarDoor;
	myCar->carDoor = myDoor;
}

Car* FordCarBuilder::GetCar(){
	return myCar;
}

RollsCarBuilder::RollsCarBuilder(){
	myCar = 0;
}

void RollsCarBuilder::CreatCar(){
	myCar = new Car;
}

void RollsCarBuilder::CreatCarBreak(){
	RollsCarBreak* myBreak = new RollsCarBreak;
	myCar->carBreak = myBreak;
}

void RollsCarBuilder::CreatCarDoor(){
	RollsCarDoor* myDoor = new RollsCarDoor;
	myCar->carDoor = myDoor;
}

Car* RollsCarBuilder::GetCar(){
	return myCar;
}