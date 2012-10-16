#include <iostream>
#include "Iterator.h"
using namespace std;

void main(){
	Recipe myRecipe1 =  Recipe("Fish Filets in Hot Chili Oil");
	Recipe myRecipe2 =  Recipe("Boiled Fish with Pickled Cabbage and Chili ");
	Recipe myRecipe3 =  Recipe("Coke Chicken");
	Recipe myRecipe4 =  Recipe("Fish ball soup");
	List<Recipe>* myRecipeList = new List<Recipe>();
	myRecipeList->Append(myRecipe1);
	myRecipeList->Append(myRecipe2);
	myRecipeList->Append(myRecipe3);
	myRecipeList->Append(myRecipe4);
	ListIterator<Recipe> myIterator = ListIterator<Recipe>(myRecipeList); 
	for(myIterator.First(); !myIterator.IsDone(); myIterator.Next()){
		myIterator.CurrentItem().Print();
	}
	while(1){
		;
	}
}