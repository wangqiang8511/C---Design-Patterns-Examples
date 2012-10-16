#include <iostream>
#include "Bridge.h"
using namespace std;

int main(){
	Device* myDevices[3];
	myDevices[0] = new Device("fridge");
	myDevices[1] = new Device("lamp");
	myDevices[2] = new Device("other type");
	myDevices[0]->SwichOn();
	myDevices[1]->SwichOn();
	myDevices[2]->SwichOn();
	myDevices[0]->SwichOff();
	myDevices[1]->SwichOff();
	myDevices[2]->SwichOff();
	while(1);
}