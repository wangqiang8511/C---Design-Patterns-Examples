#include "Memento.h"


// Class originator
Operation::Operation() : state(""){

}

Operation::~Operation(){

}

void Operation::SetOperation( char* tState ){
	state = tState;
}

OperationMemento* Operation::StoreOperation(){
	OperationMemento* tMemento = new OperationMemento();
	tMemento->SetState(state);
	return tMemento;
}

void Operation::RestoreOperation( OperationMemento* tMemento ){
	state = tMemento->GetState();
}

void Operation::DisplayState(){
	cout<<state<<endl;
}


// Class Memento
OperationMemento::~OperationMemento(){

}

OperationMemento::OperationMemento() : state(""){

}

void OperationMemento::SetState( char* tState ){
	state = tState;
}

char* OperationMemento::GetState(){
	return state;
}

// Class CareTaken
OperationCareTaken::OperationCareTaken( Operation* tOperation ) : 
										careOperation(tOperation){

}

OperationCareTaken::~OperationCareTaken(){
	delete careOperation;
}

void OperationCareTaken::Store(){
	OperationMemento* tMemento = careOperation->StoreOperation();
	operationList.push_back(tMemento);
}

void OperationCareTaken::Restore(int num ){
	if(num >= operationList.size()){
		cout<<"Can't do the restore!"<<endl;
	} else {
		careOperation->RestoreOperation(operationList[operationList.size() - 1 - num]);
	}
}