#include "AdapterObject.h"

OldVersion::OldVersion(){
}

void OldVersion::OldDisplay(int input){
	stringstream out;
	out<<input;
	cout<<out.str()<<endl;
}

NewVersion::NewVersion(int input){
	myData = input;
}

void NewVersion::Display(){
}

Adapter::Adapter(int input):NewVersion(input){
	oldVersion = new OldVersion();
}

void Adapter::Display(){
	oldVersion->OldDisplay(myData);
}

Adapter::~Adapter(){
	delete oldVersion;
}