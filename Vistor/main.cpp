#include "Visitor.h"
#include <iostream>
using namespace std;

void main(){
	CEO* myCEO = new CEO("Jobs", 1, 100000);
	CTO* myCTO = new CTO("Woz", 10000,50000);
	Secretory* mySecretary1 = new Secretory("Lisa", 4000);
	Secretory* mySecretary2 = new Secretory("Jane", 4000);
	Programmer* myProgrammer1 = new Programmer("Mike", 6000);
	Programmer* myProgrammer2 = new Programmer("Rose", 5000);
	Programmer* myProgrammer3 = new Programmer("Tom", 6000);
	myCEO->Add(myCTO);
	myCEO->Add(mySecretary1);
	myCEO->Add(mySecretary2);
	myCTO->Add(myProgrammer1);
	myCTO->Add(myProgrammer2);
	myCTO->Add(myProgrammer3);
	myCEO->ListJob();
	cout<<myCEO->CalculateSalary()<<endl;
	while(1){
		;
	}
}