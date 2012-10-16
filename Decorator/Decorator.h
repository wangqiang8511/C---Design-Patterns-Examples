/*	Decorator Pattern
*
*	This progarm is used to show how decorator pattern works.
*	In this program, we add different responsibilities to different roles.
*   All soldiers need fight. Pilot need fly. Sailor need sail. Officer need 
*   to manager all the soldiers. 
*
*
*   @ Wang Qiang  2010 NTU
*
*/

#include <iostream>
using namespace std;

// Class Soilder   Act as a component 
class Soldier{
public:
	virtual ~Soldier();
	virtual void ShowMe();
	const char * GetName();

protected:
	Soldier(const char* name);
	Soldier();

private:
	const char* sName;
};

// different soldiers
class Pilot : public Soldier{
public:
	virtual ~Pilot();
	virtual void ShowMe();
	Pilot(const char* name);
};

class Sailor : public Soldier{
public:
	virtual ~Sailor();
	virtual void ShowMe();
	Sailor(const char* name);
};

// Decorator

class Decorator : public Soldier{
public:
	Decorator(Soldier* tSoldier);
	virtual ~Decorator();
	virtual void ShowMe();

private:
	Soldier* mySoldier;
};

// Different Responsibility
class FlyDecorator : public Decorator{
public:
	FlyDecorator(Soldier* tSoldier);
	virtual ~FlyDecorator();
	virtual void ShowMe();
};

class SailDecorator : public Decorator{
public:
	SailDecorator(Soldier* tSoldier);
	virtual ~SailDecorator();
	virtual void ShowMe();
};

class ManageDecorator : public Decorator{
public:
	ManageDecorator(Soldier* tSoldier);
	virtual ~ManageDecorator();
	virtual void ShowMe();
};
