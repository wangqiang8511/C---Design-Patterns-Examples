#include "Command.h"

// Receiver Class
HouseWife::HouseWife( const char* name ) : myName(name){

}

HouseWife::~HouseWife(){}

void HouseWife::Cook(const char* dish){
	cout<<myName<<" has cooked "<<dish<<"!"<<endl;
}

void HouseWife::Clean(int roomNo){
	if (roomNo == 1){
		cout<<myName<<" has cleaned living room!"<<endl; 
	} else if (roomNo == 2){
		cout<<myName<<" has cleaned dining room!"<<endl; 
	} else if (roomNo == 3){
		cout<<myName<<" has cleaned bedroom!"<<endl; 
	}
}

void HouseWife::Wash(int clothNo){
	cout<<myName<<" has washed "<<clothNo<<" cloth!"<<endl; 
}


// Class Command
Command::~Command(){

}

Command::Command(){

}

// Class Cook
Cook::~Cook(){
	delete reciever;
}

Cook::Cook( HouseWife* tReciever, const char* dish ) : reciever(tReciever) , myDish(dish){

}

void Cook::Execute(){
	reciever->Cook(myDish);
}


// Class Clean
Clean::~Clean(){
	delete reciever;
}

Clean::Clean( HouseWife* tReciever, int tRoomNo ) : reciever(tReciever) , roomNo(tRoomNo){

}

void Clean::Execute(){
	reciever->Clean(roomNo);
}


// Class Wash
Wash::~Wash(){
	delete reciever;
}

Wash::Wash( HouseWife* tReciever, int tClothNo ) : reciever(tReciever) , clothNo(tClothNo) {

}

void Wash::Execute(){
	reciever->Wash(clothNo);
}


// Class MicroCommand
MicorCommand::~MicorCommand(){
	list<Command*>::const_iterator it;
	for (it = myCommandList.begin();  it != myCommandList.end(); it++) {
		delete *it;
	}
	myCommandList.clear();
}

MicorCommand::MicorCommand(){

}

void MicorCommand::Add( Command* tCommond ){
	myCommandList.push_back(tCommond);
}

void MicorCommand::Remove( Command* tCommand ){
	myCommandList.remove(tCommand);
}

void MicorCommand::Execute(){
	list<Command*>::const_iterator it;
	for (it = myCommandList.begin();  it != myCommandList.end(); it++) {
		(*it)->Execute();
	}
}