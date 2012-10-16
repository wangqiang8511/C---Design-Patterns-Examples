/*	Class Based Adapter
*
*	This progarm is used to show how class base adapter works.
*	In this program, we assume that there is an old version 
*   interface incompatible  to the new version interface.
*   We design an class based adapter to make to interface 
*   compatible.
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


// New version interface    // can be abstract
class NewVersion{
public:
	NewVersion(int input);
	virtual void Display();  // Can be abstract
protected:
	int myData;
};

// Adapter
class Adapter: public NewVersion, private OldVersion{
public:
	Adapter(int input);
	void Display();   // implement with the adapee
};

