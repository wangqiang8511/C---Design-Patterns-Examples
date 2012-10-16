/*	Abstract Factory
*
*	This progarm is used to show how abstract factory works.
*	In this program, we assume that one car factory need to
*   build two kinds of cars, each kind of cars has the same
*   parts but different representation.
*
*   @ Wang Qiang  2010 NTU
*
*/
#include <iostream>
using namespace std;


//Abstract product class
class CarBreak{  // The break of car   
public:
	virtual void Draw() = 0;
};

class CarDoor{	 // The door of car   
public:
	virtual void Draw() = 0;
};

// Concrete product class
class FordCarBreak : public CarBreak{
public:
	void Draw();
};

class FordCarDoor : public CarDoor{
public:
	void Draw();
};

class RollsCarBreak : public CarBreak{
public:
	void Draw();
};

class RollsCarDoor : public CarDoor{
public:
	void Draw();
};

//Abstract Factory
class CarFactory{
public:
	virtual CarBreak* CreatCarBreak() = 0;
	virtual CarDoor* CreatCarDoor() = 0;
};

//Concrete Factory
class FordCarFactory : public CarFactory{
public:
	FordCarBreak* CreatCarBreak();
	FordCarDoor* CreatCarDoor();
};

class RollsCarFactory : public CarFactory{
public:
	RollsCarBreak* CreatCarBreak();
	RollsCarDoor* CreatCarDoor();
};
