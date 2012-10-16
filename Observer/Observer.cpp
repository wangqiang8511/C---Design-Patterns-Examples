#include "Observer.h"


// Class Observer
Observer::~Observer(){

}

Observer::Observer(){

}

// Class Subject
Subject::~Subject(){
	delete observerList;
}

void Subject::Attach( Observer* tObserver ){
	observerList->push_back(tObserver);
}

void Subject::Detach( Observer* tObserver ){
	observerList->remove(tObserver);
}

void Subject::Notify(){
	list<Observer*>::iterator it;
	for(it = observerList->begin(); it != observerList->end(); it++){
		(*it)->Update(this);
	}
}

Subject::Subject(){
	observerList = new list<Observer*>;
}

char* Subject::GetState(){
	return("");
}

// Class FamilyMember
FamilyMember::~FamilyMember(){

}

FamilyMember::FamilyMember( const char* name ) : myName(name){

}

const char* FamilyMember::GetName(){
	return myName;
}


// Class Mother
Mother::Mother( const char* name ) : FamilyMember(name){

}

Mother::~Mother(){

}

void Mother::Cook( char* dish ){
	myDish = dish;
	cout<<FamilyMember::GetName()<<" has cooked "<<myDish<<"!"<<endl;
	Notify();    // Call Notify
}

char* Mother::GetState(){
	return myDish;
}

// Class Child

Child::Child( const char* name ) : FamilyMember(name){

}

Child::~Child(){

}

void Child::Update( Subject* theChangedSubject ){
	cout<<FamilyMember::GetName()<<" is eating "<<theChangedSubject->GetState()<<"!"<<endl;
}