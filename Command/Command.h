/*	Command Pattern
*
*	This program is used to show how Command pattern works.
*	In this program, house hold requests was encapsulated in 
*   Command class.
*
*   @ Wang Qiang  2010 NTU
*
*/

#include <iostream>
#include <list>
using namespace std;


// Receiver 
class HouseWife{
public:
	HouseWife(const char* name);
	~HouseWife();
	void Cook(const char* dish);
	void Clean(int roomNo);
	void Wash(int clothNo);
private:
	const char* myName;
};


// Abstract Command
class Command{
public:
	virtual ~Command();
	virtual void Execute() = 0;
protected:
	Command();
};

// Concrete Commands
class Cook : public Command{
public:
	virtual ~Cook();
	Cook(HouseWife* tReciever, const char* dish);
	virtual void Execute();
private:
	HouseWife* reciever;
	const char* myDish;
};

class Clean : public Command{
public:
	virtual ~Clean();
	Clean(HouseWife* tReciever, int tRoomNo);
	virtual void Execute();
private:
	HouseWife* reciever;
	int roomNo;
};

class Wash : public Command{
public:
	virtual ~Wash();
	Wash(HouseWife* tReciever, int tClothNo);
	virtual void Execute();
private:
	HouseWife* reciever;
	int clothNo;
};


// MicroCommand  A list of Command
class MicorCommand : public Command{
public:
	virtual ~MicorCommand();
	MicorCommand();
	void Add(Command* tCommond);
	void Remove(Command* tCommand);
	virtual void Execute();
private:
	list<Command*> myCommandList;
};

