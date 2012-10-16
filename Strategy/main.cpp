#include "Strategy.h"
#include <iostream>
using namespace std;

void main(){
	KongfuMan* master1 = new KongfuMan("Zhang Sanfeng");
	KongfuMan* master2 = new KongfuMan("Ye Weng");
	KongfuMan* master3 = new KongfuMan("Fang Zhang");
	master1->ChangeKongfu(new Taiji(master1));
	master2->ChangeKongfu(new WingChun(master2));
	master3->ChangeKongfu(new Shaolin(master3));
	master1->Attack();
	master2->Attack();
	master3->Attack();
	while(1){
		;
	}
}