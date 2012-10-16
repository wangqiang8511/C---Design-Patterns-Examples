#include <windows.h>
#include <iostream>
#include <sstream>
#include "AdapterClass.h"
using namespace std;

int main(){
	int test = 5;
	NewVersion* myInterface;
	myInterface = new Adapter(test);
	myInterface->Display();
	while(1);
}