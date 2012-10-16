/*	Chain of responsibility Pattern
*
*	This progarm is used to show how chain of responsibility pattern works.
*	In this program, we simulate a challenge strategy of a Wushu center.
*   Someone come here and challenge the center (request). The center decide 
*   who accept the challenge. (Composite pattern will be used again in this demo)
*
*   @ Wang Qiang  2010 NTU
*
*/

#include <iostream>
using namespace std;

// Here simplify the composite pattern to one concrete component
class KongfuMan{
public:
	~KongfuMan();
	KongfuMan(const char* name, int tlevel);
	void ChangeMaster(KongfuMan* tmaster);

	// Composite parts
	void Add(KongfuMan* prentice);
	void Remove(KongfuMan* prentice);

	// Responsibility (Handle request)
	void FaceChangllge(int clevel);

private:
	void ShowMe();
	const char* myName;
	int level;
	KongfuMan* master; // The master of this KongfuMan  .. as successor
};