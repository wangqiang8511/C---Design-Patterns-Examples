#include <iostream>
#include "Flyweight.h"
using namespace std;

void main(){
	WeaponStore myStore = WeaponStore();
	Gun* myGun1 = myStore.AddGun("M4A1",10);
	Gun* myGun2 = myStore.AddGun("AK47",15);
	Gun* myGun3 = myStore.PickUp("M4A1",70);
	Gun* myGun4 = myStore.PickUp("AK47",90);
	myGun1->ShowMe();  // Guns in store
	myGun2->ShowMe();  // Guns in store
	myGun3->ShowMe();  // Particular gun I picked up
	myGun4->ShowMe();  // Particular gun I picked up
	while(1){
		;
	}
}