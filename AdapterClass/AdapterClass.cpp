#include "AdapterClass.h"

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
}

void Adapter::Display(){
	OldDisplay(myData);
}