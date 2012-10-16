#include <iostream>
#include "Proxy.h"
using namespace std;

void main(){
	GunProxy myGun = GunProxy("AK47");
	myGun.ShowMe();
	myGun.Load(99);
	myGun.ShowMe();
	myGun.Shoot();
	myGun.ShowMe();
	while(1){
		;
	}
}