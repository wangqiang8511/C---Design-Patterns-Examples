/**
*	State Pattern
*
*	This example is used to show how state pattern works.
*	In this program, the mood state is simulated. One person
*   may act differently due to the different mood state.
*
*	Wang Qiang @NTU 2010
*
*/

#include <iostream>
using namespace std;

class Mood;

class Dad{
public:
	Dad(const char* name);
	~Dad();
	void LoseMoney();
	void BlazedByMother();
	void DisturbedByChild();
	void NiceDiner();
	const char* GetName();
private:
	friend class Mood;
	void ChangeMood(Mood* newMood);
private:
	Mood* myMood;
	const char* myName;
};

class Mood{
public:
	virtual ~Mood();
	virtual void LoseMoney(Dad* tDadPara);
	virtual void BlazeByMother(Dad* tDadPara);
	virtual void DisturbedByChild(Dad* tDadPara);
	virtual void NiceDinner(Dad* tDadPara);
protected:
	Mood();
protected:
	virtual void ChangeMood(Dad* tDadPara, Mood* newMood);
};

class Happy : public Mood{
public:
	Happy();
	virtual ~Happy();
	virtual void LoseMoney(Dad* tDadPara);
	virtual void BlazeByMother(Dad* tDadPara);
	virtual void DisturbedByChild(Dad* tDadPara);
	virtual void NiceDinner(Dad* tDadPara);
};

class Common : public Mood{
public:
	Common();
	virtual ~Common();
	virtual void LoseMoney(Dad* tDadPara);
	virtual void BlazeByMother(Dad* tDadPara);
	virtual void DisturbedByChild(Dad* tDadPara);
	virtual void NiceDinner(Dad* tDadPara);
};

class Angry: public Mood{
public:
	Angry();
	virtual ~Angry();
	virtual void LoseMoney(Dad* tDadPara);
	virtual void BlazeByMother(Dad* tDadPara);
	virtual void DisturbedByChild(Dad* tDadPara);
	virtual void NiceDinner(Dad* tDadPara);
};