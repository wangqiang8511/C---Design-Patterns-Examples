#include <iostream>
#include "AdapterObject.h"
using namespace std;

int main(){
	int t = 5;
	NewVersion* myInterface = new Adapter(t);
	myInterface->Display();
	while(1);
}