#include <iostream>
#include "Observer.h"
using namespace std;

void main (){
	Mother myMother = Mother("Guan Xianlan");
	Child* child1 = new Child("Li Yusha");
	Child* child2 = new Child("Wang Qiang");
	myMother.Attach(child1);
	myMother.Attach(child2);
	myMother.Cook("Pork in spicy soup");
	while (1){
		;
	}
}