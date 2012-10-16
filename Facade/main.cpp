#include <iostream>
#include "Facade.h"
using namespace std;

void main(){
	Car myCar = Car();
	myCar.OpenDoor();
	myCar.Start();
	myCar.DisplayPosition();
	myCar.Skid();
	myCar.Stop();
	myCar.LockDoor();
	while(1){
		;
	}
}