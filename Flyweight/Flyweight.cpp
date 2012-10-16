#include "Flyweight.h"

// Class Gun
Gun::~Gun(){}

Gun::Gun(const char *name) : 
						gName(name),
						bullet(0){}

Gun::Gun(const Gun &rhs){
	gName = rhs.gName;
	bullet = rhs.bullet;
}

void Gun::Load(int num){
	bullet = num;
}

bool Gun::operator == (const Gun &rhs){
	if(strcmp ( gName,  rhs.gName ) == 0)
		return true;
	else 
		return false;
}

bool Gun::operator == (const char* rhs){
	if(strcmp ( gName,  rhs) == 0)
		return true;
	else 
		return false;
}

void Gun::ShowMe(){
	cout<<"Name   :  "<<gName<<endl;
	cout<<"Bullet :  "<<bullet<<endl;
}

Gun& Gun::operator =(const Gun &rhs){
	gName = rhs.gName;
	return *this;
}

// Class GunFactory
GunFactory::~GunFactory(){
	list<Gun*>::const_iterator it;
	for (it = gunPool.begin();  it != gunPool.end(); it++) {
			delete *it;
    }
	gunPool.clear();
}

GunFactory::GunFactory(){}

Gun* GunFactory::GetGun(const char *name){
	list<Gun*>::const_iterator it;
	for (it = gunPool.begin();  it != gunPool.end(); it++) {
		if(**it==name)
			return *it;
    }
	Gun* tGun = new Gun(name);
	gunPool.push_back(tGun);
	return tGun;
}

// Class GunCheck
GunCheck::~GunCheck(){}

GunCheck::GunCheck(int n, const char *name) :
					no(n),
					gName(name){}

int GunCheck::GetNum(){
	return no;
}

void GunCheck::AddNum(int n){
	no += n;
}

bool GunCheck::operator ==(const char *rhs){
	if(strcmp ( gName,  rhs) == 0)
		return true;
	else 
		return false;
}

// Class WeaponStore 
WeaponStore::WeaponStore(){
	myFactory = new GunFactory();
}

WeaponStore::~WeaponStore(){
	gunList.clear();
}

Gun* WeaponStore::AddGun(const char *name, int num){
	bool exist = false;
	list<GunCheck>::iterator it;
	for (it = gunList.begin();  it != gunList.end(); it++) {
		if(*it==name){
			(*it).AddNum(num);
			exist = true;
		}
    }
	if(!exist){
		GunCheck mylist = GunCheck(num,name);
		gunList.push_back(mylist);
	}
	return(myFactory->GetGun(name));
}

Gun* WeaponStore::PickUp(const char *name, int bullet){
	Gun* tGun = myFactory->GetGun(name);
	Gun* newGun = new Gun(*tGun);
	newGun->Load(bullet);
	return newGun;
}