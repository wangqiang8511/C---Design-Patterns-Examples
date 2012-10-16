#include "State.h"

// Class Dad
Dad::Dad(const char* name) : myName(name), myMood(new Happy()){
	
}

Dad::~Dad(){

}

void Dad::LoseMoney(){
	myMood->LoseMoney(this);
}

void Dad::BlazedByMother(){
	myMood->BlazeByMother(this);
}

void Dad::DisturbedByChild(){
	myMood->DisturbedByChild(this);
}

void Dad::NiceDiner(){
	myMood->NiceDinner(this);
}

void Dad::ChangeMood( Mood* newMood ){
	delete myMood;
	myMood = newMood;
}

const char* Dad::GetName(){
	return myName;
}
// Class Mood

Mood::~Mood(){

}

void Mood::LoseMoney(Dad* tDadPara){

}

void Mood::BlazeByMother(Dad* tDadPara){

}

void Mood::DisturbedByChild(Dad* tDadPara){

}

void Mood::NiceDinner(Dad* tDadPara){

}

Mood::Mood(){

}

void Mood::ChangeMood( Dad* tDadPara, Mood* newMood ){
	tDadPara->ChangeMood(newMood);
}

// Class Happy

Happy::Happy(){

}

Happy::~Happy(){

}

void Happy::LoseMoney(Dad* tDadPara){
	Common* newMood = new Common();
	Mood::ChangeMood(tDadPara, newMood);
	cout<<tDadPara->GetName()<<" lose the money. However he is happy now."<<endl;
	cout<<"He turn common mood!"<<endl;
}

void Happy::BlazeByMother(Dad* tDadPara){
	Common* newMood = new Common();
	Mood::ChangeMood(tDadPara, newMood);
	cout<<tDadPara->GetName()<<" blazed by mother. However he is happy now."<<endl;
	cout<<"He turn common mood!"<<endl;
}

void Happy::DisturbedByChild(Dad* tDadPara){
	cout<<tDadPara->GetName()<<" disturbed by children. However he is happy now."<<endl;
	cout<<"He is playing with the children!"<<endl;
}

void Happy::NiceDinner(Dad* tDadPara){
	cout<<tDadPara->GetName()<<" has a nice dinner!"<<endl;
	cout<<"He is happy!"<<endl;
}

// Class Common

Common::Common(){

}

Common::~Common(){

}

void Common::LoseMoney( Dad* tDadPara ){
	Angry* newMood = new Angry();
	Mood::ChangeMood(tDadPara, newMood);
	cout<<tDadPara->GetName()<<" lose the money."<<endl;
	cout<<"He turns angry!"<<endl;
}

void Common::BlazeByMother( Dad* tDadPara ){
	Angry* newMood = new Angry();
	Mood::ChangeMood(tDadPara, newMood);
	cout<<tDadPara->GetName()<<" blazed by mother."<<endl;
	cout<<"He turns angry!"<<endl;
}

void Common::DisturbedByChild( Dad* tDadPara ){
	cout<<tDadPara->GetName()<<" disturbed by children."<<endl;
	cout<<"He feels a little bit nag!"<<endl;
}

void Common::NiceDinner( Dad* tDadPara ){
	cout<<tDadPara->GetName()<<" has a nice dinner!"<<endl;
	cout<<"He is happy!"<<endl;
}

// Class Angry

Angry::Angry(){

}

Angry::~Angry(){

}

void Angry::LoseMoney( Dad* tDadPara ){
	cout<<tDadPara->GetName()<<" lose the money."<<endl;
	cout<<"Be careful! He is already very angry!"<<endl;
}

void Angry::BlazeByMother( Dad* tDadPara ){
	cout<<tDadPara->GetName()<<" blazed by mother."<<endl;
	cout<<"Be careful! He is already very angry! He may argue with mother!"<<endl;
}

void Angry::DisturbedByChild( Dad* tDadPara ){
	cout<<tDadPara->GetName()<<" disturbed by children."<<endl;
	cout<<"He has no mood to play!"<<endl;
}

void Angry::NiceDinner( Dad* tDadPara ){
	Common* newMood = new Common();
	Mood::ChangeMood(tDadPara, newMood);
	cout<<tDadPara->GetName()<<" has a nice dinner!"<<endl;
	cout<<"His mood turns better!"<<endl;
}
