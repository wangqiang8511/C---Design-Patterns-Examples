#include <iostream>
#include "Decorator.h"
using namespace std;

void main(){
	Soldier* soldier1 = new SailDecorator(new Sailor("Zhao Hu"));
	Soldier* soldier2 = new FlyDecorator(new Pilot("Li Ang"));
	Soldier* soldier3 = new ManageDecorator(new SailDecorator(new Sailor("Xu Rongli")));
	Soldier* soldier4 = new ManageDecorator(new FlyDecorator(new Pilot("Wang Qiang")));
	soldier1->ShowMe();
	soldier2->ShowMe();
	soldier3->ShowMe();
	soldier4->ShowMe();
	while(1){
		;
	}
}