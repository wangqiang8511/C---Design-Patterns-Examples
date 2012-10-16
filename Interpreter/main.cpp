#include <iostream>
#include <string>
#include "Interpreter.h"
using namespace std;

void main(){
	// Construct the Context first
	map<string,int> Dict;
	Dict["一"] = 1;
	Dict["二"] = 2;
	Dict["三"] = 3;
	Dict["四"] = 4;
	Dict["五"] = 5;
	Dict["六"] = 6;
	Dict["七"] = 7;
	Dict["八"] = 8;
	Dict["九"] = 9;
	Evaluator myEvaluator = Evaluator();
	myEvaluator.Construct("五加二");
	double result = myEvaluator.Interprete(Dict);
	cout<<result<<endl;
	while(1){

	}
}