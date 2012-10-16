#include "Proxy.h"

// Class Gun
Gun::~Gun(){}

Gun::Gun(const char *name) :
			gName(name),
			bullet(0){}

void Gun::ShowMe(){
	cout<<"Type   :  "<<gName<<endl;
	cout<<"Bullet :  "<<bullet<<endl;
}

void Gun::Load(int num){
	bullet += num;
}

void Gun::Shoot(){
	cout<<gName<<" is shooting!"<<endl;
	bullet--;
}

// Class GunProxy
GunProxy::~GunProxy(){
	delete gun;
}

GunProxy::GunProxy(const char *name) :
			gName(name),
			bullet(0){
	gun = NULL;			
}

void GunProxy::ShowMe(){
	if(gun != NULL){
		gun->ShowMe();
	} else {
		cout<<"Type   :  "<<gName<<endl;
		cout<<"Bullet :  "<<bullet<<endl;
	}			
}

void GunProxy::Load(int num){
	if(gun != NULL){
		gun->Load(num);
	} else {
		bullet += num;
	}
}

void GunProxy::Shoot(){
	if(gun == NULL){
		gun = new Gun(gName);
		gun->Load(bullet);
	}
	gun->Shoot();
}

