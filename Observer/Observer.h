/*
*	Observer Pattern
*
*	This program is used for showing how observer pattern works
*	In this program, mother can broadcast that the dinning is done.
*   The other family member should stop be notified about this message.
*
*	WANG QIANG @NTU 2010 
*
*/

#include <iostream>
#include <list>
using namespace std;

class Subject;

class Observer{
public:
	virtual ~Observer();
	virtual void Update(Subject* theChangedSubject) = 0;
protected:
	Observer();
};

class Subject{
public:
	virtual ~Subject();
	virtual void Attach(Observer* tObserver);
	virtual void Detach(Observer* tObserver);
	virtual void Notify();
	virtual char* GetState();
protected:
	Subject();
private:
	list<Observer*>* observerList;
};

class FamilyMember{
public:
	~FamilyMember();
	FamilyMember(const char* name);
	const char* GetName();
private:
	const char* myName;
};

class Mother : public FamilyMember, public Subject{
public:
	Mother(const char* name);
	~Mother();
	void Cook(char* dish);
	char* GetState();
private:
	char* myDish;
};

class Child : public FamilyMember, public Observer{
public:
	Child(const char* name);
	~Child();
	virtual void Update(Subject* theChangedSubject);
};