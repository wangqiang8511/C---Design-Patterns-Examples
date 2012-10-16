#include "ChainOfResponsibility.h"

// Class KongfuMan
KongfuMan::~KongfuMan(){
	delete myName;
	delete master;
}

KongfuMan::KongfuMan(const char *name, int tlevel):
myName(name),
level(tlevel){
	master = NULL;
}

void KongfuMan::ShowMe(){
	cout<<"Name  : "<<myName<<endl;
	cout<<"Level : "<<level<<endl;
	cout<<"Face your chanllenge!"<<endl;
}

void KongfuMan::ChangeMaster(KongfuMan *tmaster){
	master = tmaster;
}

// Composite parts
void KongfuMan::Add(KongfuMan *prentice){
	prentice->ChangeMaster(this);
}

void KongfuMan::Remove(KongfuMan *prentice){
	prentice->ChangeMaster(NULL);
}

// Handle Request
void KongfuMan::FaceChangllge(int clevel){
	if((level < clevel) && (master != NULL)){
		master->FaceChangllge(clevel);
	} else {
		ShowMe();
	}
}
