#include <iostream>
#include "Command.h"
using namespace std;

void main(){
	HouseWife* wife = new HouseWife("Wife Li");
	HouseWife* mother = new HouseWife("Mother");
	Command* myCommand1 = new Cook(wife, "ÀÆ÷Û”„");
	Command* myCommand2 = new Clean(wife, 2);
	Command* myCommand3 = new Wash(mother, 5);
	MicorCommand commands = MicorCommand();
	commands.Add(myCommand1);
	commands.Add(myCommand2);
	commands.Add(myCommand3);
	commands.Execute();
	while (1){
	}
}