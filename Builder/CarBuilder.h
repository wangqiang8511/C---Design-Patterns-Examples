/*	Builder
*
*	This progarm is used to show how buider pattern works.
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

class Car{
public:
	CarBreak* carBreak;
	CarDoor* carDoor;

	Car();
};

// Abstract Builder
class CarBuilder{
public:
	virtual void CreatCar() = 0;
	virtual void CreatCarBreak() = 0;
	virtual void CreatCarDoor() = 0;
	virtual Car* GetCar() = 0;

protected:
	Car* myCar;
	CarBuilder();
};

// Concrete Builder
class FordCarBuilder : public CarBuilder{
public:
	FordCarBuilder();
	void CreatCar();
	void CreatCarBreak();
	void CreatCarDoor();
	Car* GetCar();
};

class RollsCarBuilder : public CarBuilder{
public:
	RollsCarBuilder();
	void CreatCar();
	void CreatCarBreak();
	void CreatCarDoor();
	Car* GetCar();
};

// Director
class CarMaker{
public:
	static Car* MakeCar(CarBuilder& builder);
};
