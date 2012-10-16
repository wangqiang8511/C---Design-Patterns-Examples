/*	Object Based Adapter
*
*	This progarm is used to show how object base adapter works.
*	In this program, we assume that there is an old version 
*   interface incompatible  to the new version interface.
*   We design an class based adapter to make to interface 
*   compatible. The interface can have multi-versions with the 
*   help of Abstract Factory Pattern
*
*   @ Wang Qiang  2010 NTU
*
*/

#include <iostream>
#include <sstream>
using namespace std;


// Old version interface
class OldVersion{
public:
	OldVersion();
	void OldDisplay(int input);
};


// New version interface
class NewVersion{
public:
	NewVersion(int input);
	virtual void Display();
protected:
	int myData;
};

// Adapter
class Adapter: public NewVersion{
public:
	Adapter(int input);
	void Display();
	~Adapter();
private:
	OldVersion* oldVersion;
};

