/*	Flyweight Pattern
*
*	This progarm is used to show how flyweight pattern works.
*	In this program, we assume that there is a weapon store.
*   We store different kind of guns there. If one kind of gun 
*   is picked up, it is extrinsic.
*
*   @ Wang Qiang  2010 NTU
*
*/

#include <iostream>
#include <list>
using namespace std;


// Class Gun (Flyweight)
class Gun{
public:
	~Gun();
	Gun(const char* name);
	Gun(const Gun& rhs);
	void Load(int num);
	void ShowMe();
	bool operator == (const Gun& rhs);
	bool operator == (const char* rhs);
	Gun& operator = (const Gun& rhs);
private:
	const char* gName;  // intrinsic
	int bullet;         // extrinsic
};

// Class GunFactory (FlyweightFactory)
class GunFactory{
public:
	~GunFactory();
	GunFactory();
	Gun* GetGun(const char* name);
private:
	list<Gun*> gunPool;
};

// Class GunCheck
class GunCheck{
public:
	~GunCheck();
	GunCheck(int n, const char* name);
	int GetNum();
	void AddNum(int n);
	bool operator ==(const char* rhs);
private:
	int no;
	const char* gName;
};

// Class WeaponStore (Client)
class WeaponStore{
public:
	~WeaponStore();
	WeaponStore();
	Gun* AddGun(const char* name, int num);
	Gun* PickUp(const char* name, int bullet);
private:
	list<GunCheck> gunList; 
	GunFactory* myFactory;
};