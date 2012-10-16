#include "Iterator.h"
// Class Recipe
Recipe::~Recipe(){

}

Recipe::Recipe( const char* tName ) : name(tName){

}

void Recipe::Print(){
	cout<<name<<endl;
}