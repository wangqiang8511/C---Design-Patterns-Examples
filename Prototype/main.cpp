#include <iostream>
#include "Prototype.h"
using namespace std;

int main(){
	PrototypeManager myProduct = PrototypeManager();
	Product* A;
	Product* B;
	A = myProduct.CreateProduct(FOOD);
	B = myProduct.CreateProduct(BOOK);
	A->ShowMe();
	B->ShowMe();
	A = myProduct.CreateProduct(BOOK);
	A->ShowMe();
	while(1){
	
	}
}