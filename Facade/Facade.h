/*	Facade Pattern
*
*	This progarm is used to show how facade pattern works.
*	In this program, we simulate a car subsystem. In this
*   system, we have the door, the engine, the break, the GPS.
*   We use a facade pattern to couple all these things together.
*
*   @ Wang Qiang  2010 NTU
*
*/


#include <iostream>
using namespace std;

// Parts of the car
// Class Door
class Door{
public:
	virtual ~Door();
	Door();
	virtual void Open();
	virtual void Close();
};

// Class Engine
class Engine{
public:
	virtual ~Engine();
	Engine();
	virtual void Start();
	virtual void Stop();
};

// Class Break
class Brake{
public:
	virtual ~Brake();
	Brake();
	virtual void Skid();
};

// Class GPS
class GPS{
public:
	virtual ~GPS();
	GPS();
	virtual void Open();
	virtual void TurnOff();
	virtual void GetPosition();
	virtual void DisplayPosition();

private:
	double longitude;
	double latitude;
};

// Facade class
class Car{
public:
	virtual ~Car();
	Car();
	virtual void OpenDoor();
	virtual void LockDoor();
	virtual void Start();
	virtual void Skid();
	virtual void Stop();
	virtual void DisplayPosition();
private:
	Door* myDoor;
	Engine* myEngine;
	GPS* myGPS;
	Brake* myBrake;
};
