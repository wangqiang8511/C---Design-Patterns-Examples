#include <iostream>
#include "ChainOfResponsibility.h"
using namespace std;

void main(){
	KongfuMan* head = new KongfuMan("Wang Chongyang", 100);
	KongfuMan* s1 = new KongfuMan("Ma Yu" , 92);
	KongfuMan* s2 = new KongfuMan("Tan Zhangzhen" , 88);
	KongfuMan* s3 = new KongfuMan("Liu Changsheng" , 87);
	KongfuMan* s4 = new KongfuMan("Qiu Chuji" , 93);
	KongfuMan* s5 = new KongfuMan("Wang Chuyi" , 90);
	KongfuMan* s6 = new KongfuMan("Hao Datong" , 89);
	KongfuMan* s7 = new KongfuMan("Sun Buer" , 86);
	KongfuMan* ss1 = new KongfuMan("Yang Kong" , 90);
	KongfuMan* ss2 = new KongfuMan("Zhao Zhijing" , 83);
	KongfuMan* ss3 = new KongfuMan("Ying Zhiping" , 85);
	KongfuMan* ss4 = new KongfuMan("Guo Jing" , 96);
	head->Add(s1);
	head->Add(s2);
	head->Add(s3);
	head->Add(s4);
	head->Add(s5);
	head->Add(s6);
	head->Add(s7);
	s1->Add(ss4);
	s5->Add(ss2);
	s4->Add(ss1);
	s4->Add(ss3);
	ss1->FaceChangllge(84);
	ss1->FaceChangllge(93);
	ss2->FaceChangllge(84);
	ss2->FaceChangllge(93);
	ss3->FaceChangllge(84);
	ss3->FaceChangllge(93);
	ss4->FaceChangllge(84);
	ss4->FaceChangllge(93);
	while(1){
		;
	}
}

