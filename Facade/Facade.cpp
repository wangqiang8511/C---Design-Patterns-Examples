#include "Facade.h"

// Class Door
Door::Door(){}

Door::~Door(){}

void Door::Open(){
	cout<<"The Door is open!"<<endl;
}

void Door::Close(){
	cout<<"The Door is locked!"<<endl;
}

// Class Engine
Engine::Engine(){}

Engine::~Engine(){}

void Engine::Start(){
	cout<<"The Engine is started!"<<endl;
}

void Engine::Stop(){
	cout<<"The Engine is stopped!"<<endl;
}

// Class Brake
Brake::Brake(){}

Brake::~Brake(){}

void Brake::Skid(){
	cout<<"The car is skidded!"<<endl;
}

// Class GPS
GPS::GPS() : longitude(0),
				  latitude(0){
}

GPS::~GPS(){}

void GPS::Open(){
	cout<<"GPS is open!"<<endl;
}

void GPS::TurnOff(){
	cout<<"GPS is turned off!"<<endl;
}

void GPS::GetPosition(){
	longitude = 100.55;
	latitude = 1.14;
}

void GPS::DisplayPosition(){
	cout<<"Position:"<<endl;
	cout<<"  Longitude:"<<longitude<<endl;
	cout<<"  Latitude :"<<latitude<<endl;
}

// Class Car
Car::Car(){
	myDoor = new Door();
	myEngine = new Engine();
	myGPS = new GPS();
	myBrake = new Brake();
}

void Car::OpenDoor(){
	myDoor->Open();
}

void Car::LockDoor(){
	myDoor->Close();
}

void Car::Start(){
	myEngine->Start();
	myGPS->Open();
}

void Car::Skid(){
	myBrake->Skid();
}

void Car::Stop(){
	myEngine->Stop();
	myGPS->TurnOff();
}

void Car::DisplayPosition(){
	myGPS->GetPosition();
	myGPS->DisplayPosition();
}

Car::~Car(){
	delete myDoor;
	delete myEngine;
	delete myGPS;
	delete myBrake;
}