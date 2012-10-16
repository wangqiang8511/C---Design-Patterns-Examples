/*	Proxy Pattern
*
*	This progarm is used to show how proxy pattern works.
*	In this program, we simulate the weapon store again.
*   Gun is dangeous. We use virtual proxy to get basic 
*   access to the gun. If you really need the gun, we give
*   you the real gun.
*
*   @ Wang Qiang  2010 NTU
*
*/

#include <iostream>
using namespace std;

class Gun{
public:
	~Gun();
	Gun(const char* name);
	void ShowMe();
	void Load(int num);
	void Shoot();

private:
	const char* gName;
	int bullet;
};


// Virtual Proxy  // Only when the gun is shooting, return the real gun
class GunProxy{
public:
	~GunProxy();
	GunProxy(const char* name);
	void ShowMe();
	void Load(int num);
	void Shoot();

private:
	Gun* gun;
	const char* gName;
	int bullet;
};
