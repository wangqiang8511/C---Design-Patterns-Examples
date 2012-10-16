#include <windows.h>
#include <iostream>
#include "FactoryMethod.h"
using namespace std;




int main(){

	Car* A;
	Car* B;
	CarCreator myCarCreator;
	A = myCarCreator.CreatCar(FORD);
	B = myCarCreator.CreatCar(ROLLS);
	A->carBreak->Draw();
	A->carDoor->Draw();
	B->carBreak->Draw();
	B->carDoor->Draw();
	while(1);
}