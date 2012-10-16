/**
*	Strategy Pattern
*
*	This example is used for showing how strategy pattern works.
*   Kongfuman was used again to illustrate the usage of strategy.
*
*	Wang Qiang @NTU 2010
*/

#include <iostream>
using namespace std;

class Kongfu;

// Class Context
class KongfuMan{
public:
	KongfuMan(const char* name);
	~KongfuMan();
	void Attack();
	void ChangeKongfu(Kongfu* newKongfu);
	const char* GetName();
private:
	Kongfu* myKongfu;
	const char* myName;
};

// Class Strategy
class Kongfu{
public:
	Kongfu(KongfuMan* tMan);
	virtual ~Kongfu();
	virtual void Attack();
protected:
	KongfuMan* myKongfuMan;
};

class WingChun : public Kongfu{
public:
	WingChun(KongfuMan* tMan);
	virtual ~WingChun();
	virtual void Attack();
};

class Taiji : public Kongfu{
public:
	Taiji(KongfuMan* tMan);
	virtual ~Taiji();
	virtual void Attack();
};

class Shaolin : public Kongfu{
public:
	Shaolin(KongfuMan* tMan);
	virtual ~Shaolin();
	virtual void Attack();
};
