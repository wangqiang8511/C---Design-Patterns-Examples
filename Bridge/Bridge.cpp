#include "Bridge.h"


// Device
Device::Device(char *type){
	typeName = type;
	if(!strcmp(typeName,"fridge")){
		imp = new FridgeImplement();
	}
	else if(!strcmp(typeName,"lamp")){
		imp = new LampImplement();
	}
	else{
		imp = new DeviceImplement();
	}
}

Device::~Device(){
	delete typeName;
	delete imp;
}

void Device::SwichOn(){
	imp->SwichOn();
}

void Device::SwichOff(){
	imp->SwichOff();
}

// DeviceImplement
DeviceImplement::DeviceImplement(){

}

void DeviceImplement::SwichOn(){
	cout<<"General Electric Device: On!"<<endl;
}

void DeviceImplement::SwichOff(){
	cout<<"General Electric Device: Off!"<<endl;
}

// FridgeImplement
FridgeImplement::FridgeImplement(){

}

void FridgeImplement::SwichOn(){
	cout<<"Fridge: On!"<<endl;
}

void FridgeImplement::SwichOff(){
	cout<<"Fridge: Off!"<<endl;
}

// LampImplement
LampImplement::LampImplement(){

}

void LampImplement::SwichOn(){
	cout<<"Lamp: On!"<<endl;
}

void LampImplement::SwichOff(){
	cout<<"Lamp: Off!"<<endl;
}