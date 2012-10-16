/*
*	Iterator Pattern
*
*	This program is used for showing how iterator pattern works
*	In this program, an external iterator is applied to access 
*   the list of recipe.
*
*
*	WANG QIANG @NTU 2010 
*
*/

#include <iostream>
#include "List.h"
using namespace std;


// Class Recipe
class Recipe{
public:
	~Recipe();
	Recipe(const char* tName);
	void Print();
private:
	const char* name;
};


// Class Iterator
template <class Item>
class Iterator{
public:
	virtual ~Iterator();
	virtual void First() = 0;
	virtual void Next() = 0;
	virtual bool IsDone() = 0;
	virtual Item CurrentItem() = 0;
protected:
	Iterator();
};


// Class List Iterator
template <class Item>
class ListIterator : public Iterator<Item> {
public:
	ListIterator(const List<Item>* tList);
	virtual ~ListIterator();
	virtual void First();
	virtual void Next();
	virtual bool IsDone();
	virtual Item CurrentItem();

private:
	const List<Item>* myList;
	long current;
};



// Class Iterator
template <class Item>
Iterator<Item>::~Iterator(){

}
template <class Item>
Iterator<Item>::Iterator(){

}

//Class ListIterator
template <class Item>
ListIterator<Item>::~ListIterator(){
	delete myList;
}

template <class Item>
ListIterator<Item>::ListIterator( const List<Item>* tList ) : 
myList(tList),
current(0){

}

template <class Item>
Item ListIterator<Item>::CurrentItem(){
	if(IsDone()){
		cout<<"Out of Boundary"<<endl;
		return NULL;
	} else {
		return myList->Get(current);
	}
}

template <class Item>
bool ListIterator<Item>::IsDone(){
	return current > myList->Size();
}

template <class Item>
void ListIterator<Item>::Next(){
	current++;
}

template <class Item>
void ListIterator<Item>::First(){
	current = 1;
}
