#include "Mediator.h"


// Class FamilyDirector
FamilyDirector::FamilyDirector(){
	myMother = new Mother(this);
	myFather = new Father(this);
	myChild = new Child(this);
	myGrandma = new Grandam(this);
}

FamilyDirector::~FamilyDirector(){
	delete myMother;
	delete myFather;
	delete myChild;
	delete myGrandma;
}

void FamilyDirector::HandleEvent( FamilyMember* sender ){
	if (strcmp(sender->GetRequest(), "Wash Cloth!") == 0){
		myMother->Wash();
	} else if (strcmp(sender->GetRequest(), "Clean Room!") == 0) {
		myMother->Clean();
	} else if (strcmp(sender->GetRequest(), "Cook Dinner!") == 0) {
		myMother->Cook();
	} else if ((sender == myChild) && (strcmp(sender->GetRequest(), "I want to sleep!") == 0)) {
		myGrandma->lull();
		myChild->Sleep();
	} else if ((sender == myChild) && (strcmp(sender->GetRequest(), "I want to study!") == 0)){
		myFather->Teach();
		myChild->Study();
	} else if ((sender == myMother) && (strcmp(sender->GetRequest(), "Shower!") == 0)){
		myChild->Shower();
	} else if ((sender == myMother) && (strcmp(sender->GetRequest(), "Work!") == 0)){
		myFather->Work();
	}
}

Mother* FamilyDirector::GetMother(){
	return myMother;
}

Father* FamilyDirector::GetFather(){
	return myFather;
}

Child* FamilyDirector::GetChild(){
	return myChild;
}

Grandam* FamilyDirector::GetGrandam(){
	return myGrandma;
}

// Class FamilyMember
FamilyMember::FamilyMember( FamilyDirector* tDirector ) : 
						myDirector(tDirector) ,
						myRequest(""){

}

FamilyMember::~FamilyMember(){
	delete myDirector;
}

void FamilyMember::SendRequest(){
	myDirector->HandleEvent(this);
}

void FamilyMember::SetRequest( char* tRequest ){
	myRequest = tRequest;
}

char* FamilyMember::GetRequest(){
	return myRequest;
}
// Class Mother
Mother::Mother( FamilyDirector* tDirector ) : FamilyMember(tDirector){
	
}

void Mother::Cook(){
	cout<<"Mom is cooking!"<<endl;
}

void Mother::Clean(){
	cout<<"Mom is cleaning the rooms!"<<endl;
}

void Mother::Wash(){
	cout<<"Mom is washing cloth!"<<endl;
}


// Class father
Father::Father( FamilyDirector* tDirector ) : FamilyMember(tDirector){

}

void Father::Teach(){
	cout<<"Dad is teach little baby!"<<endl;
}

void Father::Work(){
	cout<<"Dad is working!"<<endl;
}

// Class Child
Child::Child( FamilyDirector* tDirector ) : FamilyMember(tDirector){

}

void Child::Study(){
	cout<<"The baby is studying!"<<endl;
}

void Child::Shower(){
	cout<<"The baby is showering!"<<endl;
}

void Child::Sleep(){
	cout<<"The baby is sleeping!"<<endl;
}

// Class Grandma
Grandam::Grandam( FamilyDirector* tDirector ) : FamilyMember(tDirector) {

}

void Grandam::lull() {
	cout<<"The grandma is singing the baby to sleep!"<<endl;
}