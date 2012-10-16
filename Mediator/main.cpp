#include <iostream>
#include "Mediator.h"
using namespace std;

void main(){
	FamilyDirector myDirector = FamilyDirector();
	myDirector.GetChild()->SetRequest("I want to sleep!");
	myDirector.GetChild()->SendRequest();
	myDirector.GetFather()->SetRequest("Clean Room!");
	myDirector.GetFather()->SendRequest();
	myDirector.GetMother()->SetRequest("Shower!");
	myDirector.GetMother()->SendRequest();
	while(1){
		;
	}
}