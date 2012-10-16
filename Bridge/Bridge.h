/*	Bridge Pattern
*
*	This program is used to show how Bridge pattern works.
*	In this program, separate the switch on and switch off 
*   implementation of electric devices
*
*   @ Wang Qiang  2010 NTU
*
*/

#include <iostream>
using namespace std;



// Implementor
class DeviceImplement{
public:
	DeviceImplement();
	virtual void SwichOn();
	virtual void SwichOff();
};

class FridgeImplement : public DeviceImplement{
public:
	FridgeImplement();
	virtual void SwichOn();
	virtual void SwichOff();
};


class LampImplement : public DeviceImplement{
public:
	LampImplement();
	virtual void SwichOn();
	virtual void SwichOff();
};


// Abstraction
class Device{
public:
	Device(char* type);
	~Device();
	void SwichOn();
	void SwichOff();
private:
	char* typeName;
	DeviceImplement* imp;
};
