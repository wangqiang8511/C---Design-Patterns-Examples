/*	Factory Method
*
*	This progarm is used to show how factory Method works.
*	In this program, we assume that one car factory need to
*   build two kinds of cars, each kind of cars has the same
*   parts but different representation.
*
*   @ Wang Qiang  2010 NTU
*
*/

#include <iostream>
using namespace std;


#define FORD 1
#define ROLLS 2

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

class Car{
public:
	CarBreak* carBreak;
	CarDoor* carDoor;

	Car();
};

// Creator
class CarCreator{
public:

	Car* CreatCar(int ID);

	// Factory Method
	virtual CarBreak* CreatBreak(int ID) const;
	virtual CarDoor* CreatDoor(int ID) const;

};

//class FordCarCreator : public CarCreator{
//public:
//	virtual CarBreak* CreatBreak() = 0;
//	virtual CarDoor* CreatCarDoor() = 0;
//};
//
//class RollsCarCreator : public CarCreator{
//public:
//	virtual CarBreak* CreatBreak() = 0;
//	virtual CarDoor* CreatCarDoor() = 0;
//};