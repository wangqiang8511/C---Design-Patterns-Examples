/*
*	Prototype Pattern
*
*	This example show how to use prototype pattern in C++
*   The scence is you are doing shoping in the Mall and you
*	have not decided whick kind of products you want to buy.
*   The structure of different kind of products are quite different.
*	However the structure of the same kind of products are the same.
*
*	Prototype patttern make the modification of the created objects more easier.
*
*	Wang Qiang  @NTU
*/

#include <iostream>
#include <map>
#include <string>
using namespace std;

// Product type enum
enum PRODUCT_TYPE{
	FOOD,
	BOOK
};

// Abstract Products class
class Product{
public:
	virtual Product* clone() = 0;
	virtual void ShowMe() = 0;
protected:
	string prouductName;
	float price;
};


// Concrete Products class
class FoodProduct : public Product{
public:
	FoodProduct();
	FoodProduct(string tFoodName, float tFoodPrice, int tExpireDay);
	FoodProduct(FoodProduct& tFoodProduct);
	virtual Product* clone();
	virtual void ShowMe();
protected:
	int expireDay;
};

class BookProduct : public Product{
public:
	BookProduct();
	BookProduct(string tBookName, float tBookPrice,string tAuthor);
	BookProduct(BookProduct& tBookProduct);
	virtual Product* clone();
	virtual void ShowMe();
protected:
	string author;
};

// Prototype Manager
class PrototypeManager{
public:
	PrototypeManager();
	~PrototypeManager();
	Product* CreateProduct(PRODUCT_TYPE en);
private:
	map<PRODUCT_TYPE,Product*> mapProduct;
};