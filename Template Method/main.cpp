#include "TemplateMethod.h"
#include <iostream>
using namespace std;

void main(){
	HiguchiAlgorithm myMethod1 = HiguchiAlgorithm();
	BoxcountingAlgorithm myMethod2 = BoxcountingAlgorithm();
	myMethod1.EEGDataProcess();
	myMethod2.EEGDataProcess();
	while(1){
		;
	}
}