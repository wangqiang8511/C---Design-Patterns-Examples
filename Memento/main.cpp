#include <iostream>
#include "Memento.h"
using namespace std;

void main(){

	Operation* myOperation = new Operation();
	OperationCareTaken myCareTaken = OperationCareTaken(myOperation);
	myOperation->SetOperation("Get Up!");
	myCareTaken.Store();
	myOperation->SetOperation("Toothbrushing!");
	myCareTaken.Store();
	myOperation->SetOperation("Face Washing!");
	myCareTaken.Store();
	myOperation->SetOperation("Cook Breakfast!");
	myCareTaken.Store();
	myOperation->SetOperation("Have a breakfast!");
	myCareTaken.Store();
	myOperation->SetOperation("Go for working!");
	myCareTaken.Store();
	myOperation->DisplayState();
	myCareTaken.Restore(5);
	myOperation->DisplayState();
	while(1){
		;
	}
}