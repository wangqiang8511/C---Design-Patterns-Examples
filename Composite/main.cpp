#include <iostream>
#include "Composite.h"
using namespace std;

void main(){
	Building myBuilding = Building("Graduate Hall");
	Lobby lobby1 = Lobby("Lobby 1");
	Lobby lobby2 = Lobby("Lobby 2");
	Lift lift1 = Lift("Lift 1");
	Lift lift2 = Lift("Lift 2");
	Lift lift3 = Lift("Fireman Lift");
	Unit unit1 = Unit("Unit 1");
	Unit unit2 = Unit("Unit 2");
	Level level1 = Level("Level B2");
	Level level2 = Level("Level B1");
	Level level3 = Level("Level 1");
	Level level4 = Level("Level B2");
	Level level5 = Level("Level B1");
	Level level6 = Level("Level 1");
	Room room1 = Room("Room B2-01");
	Room room2 = Room("Room B2-02");
	Room room3 = Room("Room B2-03");
	Room room4 = Room("Room B2-04");
	Room room5 = Room("Room B1-01");
	Room room6 = Room("Room B1-02");
	Room room7 = Room("Room B1-03");
	Room room8 = Room("Room B1-04");
	myBuilding.Add(&lift3);
	myBuilding.Add(&unit1);
	myBuilding.Add(&unit2);
	unit1.Add(&lift1);
	unit2.Add(&lift2);
	unit1.Add(&level1);
	unit1.Add(&level2);
	unit1.Add(&level3);
	unit2.Add(&level4);
	unit2.Add(&level5);
	unit2.Add(&level6);
	level1.Add(&room1);
	level1.Add(&room2);
	level4.Add(&room3);
	level4.Add(&room4);
	level2.Add(&room5);
	level2.Add(&room6);
	level5.Add(&room7);
	level5.Add(&room8);
	level3.Add(&lobby1);
	level6.Add(&lobby2);
	myBuilding.ShowMe();
	while(1){
		;
	}
}