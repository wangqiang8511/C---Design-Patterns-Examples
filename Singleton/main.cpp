#include <iostream>
#include "Singleton.h"
using namespace std;

int main(){
	SingletonEarth* earth;
	earth = SingletonEarth::Instance();
	earth->Show();
	while(1){
	
	}
}