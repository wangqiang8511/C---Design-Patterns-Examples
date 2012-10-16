#include "Strategy.h"

// Class KongfuMan

KongfuMan::KongfuMan( const char* name ) :
					myName(name){
	myKongfu = new Kongfu(this);
}

KongfuMan::~KongfuMan(){
	delete myKongfu;
}

void KongfuMan::Attack(){
	myKongfu->Attack();
}

void KongfuMan::ChangeKongfu( Kongfu* newKongfu ){
	delete myKongfu;
	myKongfu = newKongfu;
}

const char* KongfuMan::GetName(){
	return myName;
}


// Class Kongfu
Kongfu::Kongfu(KongfuMan* tMan) : myKongfuMan(tMan){

}

Kongfu::~Kongfu(){
	//delete myKongfuMan;
}

void Kongfu::Attack(){
	cout<<myKongfuMan->GetName()<<": Show basic kong fu!"<<endl;
}

// Class Wing Chun
WingChun::WingChun( KongfuMan* tMan ) : Kongfu(tMan){

}

WingChun::~WingChun(){

}

void WingChun::Attack(){
	cout<<myKongfuMan->GetName()<<": Show Wing Chun!"<<endl;
}

// Class Taiji
Taiji::Taiji( KongfuMan* tMan ) : Kongfu(tMan){

}

Taiji::~Taiji(){

}

void Taiji::Attack(){
	cout<<myKongfuMan->GetName()<<": Show Tai Ji!"<<endl;
}

// Class Shao Lin

Shaolin::Shaolin(KongfuMan* tMan) : Kongfu(tMan){

}

Shaolin::~Shaolin(){

}

void Shaolin::Attack(){
	cout<<myKongfuMan->GetName()<<": Show Shao lin kongfu!"<<endl;
}