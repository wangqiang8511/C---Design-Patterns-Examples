/*
*	Memento Pattern
*
*   This sample is used for introduce the memento pattern.
*   A operation list is generated and stored with the help
*   of memento pattern.
*
*	Wang Qiang @NTU 2010
*
*/

#include <iostream>
#include <vector>
using namespace std;

class Operation;
class OperationMemento;

// Class originator
class Operation{
public:
	Operation();
	~Operation();
	void SetOperation(char* tState);
	OperationMemento* StoreOperation();
	void RestoreOperation(OperationMemento* tMemento);
	void DisplayState();
private:
	char* state;
};

// Class Memento
class OperationMemento{
public:
	~OperationMemento();
private:
	friend class Operation;
	OperationMemento();
	void SetState(char* tState);
	char* GetState();
	
private:
	char* state;
};

// Class CareTaken
class OperationCareTaken{
public:
	OperationCareTaken(Operation* tOperation);
	~OperationCareTaken();
	void Store();
	void Restore(int num);
private:
	vector<OperationMemento*> operationList;
	Operation* careOperation;
};