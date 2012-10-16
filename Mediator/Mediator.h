/*
*	Mediator Pattern
*
*	This program is used for showing how mediator pattern works
*	In this program, a mediator is used for simulating the interaction
*	between family members.
*
*	WANG QIANG @NTU 2010 
*
*/

#include <iostream>
#include <string.h>
using namespace std;

// Forward declaration 
class FamilyDirector;

class FamilyMember{
public:
	FamilyMember(FamilyDirector* tDirector);
	~FamilyMember();
	void SendRequest();
	void SetRequest(char* tRequest);
	char* GetRequest();
protected:
	FamilyDirector* myDirector;
	char* myRequest;
};

class Mother : public FamilyMember{
public:
	Mother(FamilyDirector* tDirector);
	void Cook();
	void Clean();
	void Wash();
};

class Father : public FamilyMember{
public:
	Father(FamilyDirector* tDirector);
	void Teach();
	void Work();
};

class Child : public FamilyMember{
public:
	Child(FamilyDirector* tDirector);
	void Study();
	void Shower();
	void Sleep();
};

class Grandam : public FamilyMember{
public:
	Grandam(FamilyDirector* tDirector);
	void lull();
};

class FamilyDirector {
public:
	FamilyDirector();
	virtual ~FamilyDirector();
	virtual void HandleEvent(FamilyMember* sender);
	Mother* GetMother();
	Father* GetFather();
	Child*  GetChild();
	Grandam* GetGrandam();
private:
	Mother* myMother;
	Father* myFather;
	Child* myChild;
	Grandam* myGrandma;
};

