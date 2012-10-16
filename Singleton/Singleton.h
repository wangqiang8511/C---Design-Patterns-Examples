/*
*	Singleton Pattern
*
*   This program will show how singleton pattern works in c++
*	I will create an earth object, which one can only has one 
*   instance.
*
*	Wang Qiang @NTU
*/

#include <iostream>
using namespace std;

class SingletonEarth{
public:
	static SingletonEarth* Instance();
	void Show();
protected:
	SingletonEarth();
private:
	static SingletonEarth* instance;
};