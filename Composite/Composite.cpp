#include "Composite.h"


// Component
// Class Architecture
Architecture::~Architecture(){
	delete bName;
}

const char* Architecture::GetName(){
	return bName;
}

void Architecture::ShowMe() {
	cout<<"Architecture:"<<bName<<endl;
}

Architecture::Architecture(const char *name) : bName(name){}

void Architecture::setName(const char *name){
	bName = name;
}

void Architecture::Add(Architecture *element){}

void Architecture::Remove(Architecture *element){}

list<Architecture*> Architecture::GetChild(){ list<Architecture*> tV;  return tV;}

// Leaf
// Class LeafArchitecture
LeafArchitecture::~LeafArchitecture(){}

LeafArchitecture::LeafArchitecture(const char *name):Architecture(name){}

void LeafArchitecture::ShowMe(){
	cout<<"LeafArchitecture:"<<GetName()<<endl;
}


// Class Lobby
Lobby::Lobby(const char *name):LeafArchitecture(name){}


Lobby::~Lobby(){}

void Lobby::ShowMe() {
	cout<<"Lobby:"<<GetName()<<endl;
}

// Class Room
Room::Room(const char *name):LeafArchitecture(name){}

Room::~Room(){}

void Room::ShowMe(){
	cout<<"Room:"<<GetName()<<endl;
}

// Class Lift
Lift::Lift(const char *name):LeafArchitecture(name){}

Lift::~Lift(){}

void Lift::ShowMe(){
	cout<<"Lift:"<<GetName()<<endl;
}

// Composite
// Class CompositeArchitecture
CompositeArchitecture::~CompositeArchitecture(){
	list<Architecture*>::const_iterator it;
	for (it = architectureList.begin();  it != architectureList.end(); it++) {
			(*it)->ShowMe();
			delete *it;
    }
	architectureList.clear();
}

CompositeArchitecture::CompositeArchitecture(const char *name) : Architecture(name) {}

void CompositeArchitecture::ShowMe() const{
	list<Architecture*>::const_iterator it;
	for (it = architectureList.begin();  it != architectureList.end(); it++) {
			Architecture& a = **it;
			a.ShowMe();
   }
}

void CompositeArchitecture::Add(Architecture *element){
	architectureList.push_back(element);
}

void CompositeArchitecture::Remove(Architecture *element){
	architectureList.remove(element);
}

list<Architecture*>  CompositeArchitecture::GetChild(){
	return architectureList;
}

// Class Building
Building::Building(const char *name):CompositeArchitecture(name){}

Building::~Building(){}

void Building::ShowMe(){
	cout<<"Building:"<<GetName()<<endl;
	CompositeArchitecture::
	CompositeArchitecture::ShowMe();
}


// Class Unit
Unit::Unit(const char *name):CompositeArchitecture(name){}

Unit::~Unit(){}

void Unit::ShowMe(){
	cout<<"Unit:"<<GetName()<<endl;
	CompositeArchitecture::ShowMe();
}

// Class Level
Level::Level(const char *name):CompositeArchitecture(name){}

Level::~Level(){}

void Level::ShowMe(){
	cout<<"Level:"<<GetName()<<endl;
	CompositeArchitecture::ShowMe();
}
