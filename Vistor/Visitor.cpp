#include "Visitor.h"


// Class Employee
Employee::~Employee(){

}

Employee::Employee( const char* name, int money ) :
				myName(name),
				salary(money){

}

int Employee::GetSalary(){
	return salary;
}

const char* Employee::GetName(){
	return myName;
}

void Employee::Add( Employee* tEmployee ){

}

void Employee::Remove( Employee* tEmployee ){

}
// Class CEO

CEO::CEO( const char* name, int money, int tbonus ) : 
		Employee(name, money),
		bonus(tbonus){
	myEmployeeList = new list<Employee*>;
}

CEO::~CEO(){
	delete myEmployeeList;
}

void CEO::Accept( Visitor& tVisitor ){
	list<Employee*>::iterator it;
	for(it = myEmployeeList->begin(); it != myEmployeeList->end(); it++){
		(*it)->Accept(tVisitor);
	}
	tVisitor.VisitCEO(this);
}

void CEO::ShowMyJob(){
	cout<<Employee::GetName()<<": Manager the company (CEO)!"<<endl;
}

void CEO::Add( Employee* tEmployee ){
	myEmployeeList->push_back(tEmployee);
}

void CEO::Remove( Employee* tEmployee ){
	myEmployeeList->remove(tEmployee);
}

int CEO::GetBonus(){
	return bonus;
}

int CEO::CalculateSalary(){
	PaymentVisitor payment = PaymentVisitor();
	this->Accept(payment);
	return(payment.GetMoney());
}

void CEO::ListJob(){
	JobVisitor showJob = JobVisitor();
	this->Accept(showJob);
}
// Class Secretory

Secretory::Secretory( const char* name, int money ) : 
					Employee(name, money){

}

Secretory::~Secretory(){

}

void Secretory::Accept( Visitor& tVisitor ){
	tVisitor.VisitSecretary(this);
}

void Secretory::ShowMyJob(){
	cout<<Employee::GetName()<<": Paper works (Secretory)!"<<endl;
}

// Class CTO
CTO::CTO( const char* name, int money, int tbonus ) : 
		Employee(name, money),
		bonus(tbonus){
	myEmployeeList = new list<Employee*>;
}

CTO::~CTO(){
	delete myEmployeeList;
}

void CTO::Accept( Visitor& tVisitor ){
	list<Employee*>::iterator it;
	for (it = myEmployeeList->begin(); it != myEmployeeList->end(); it++){
		(*it)->Accept(tVisitor);
	}
	tVisitor.VisitCTO(this);
}

void CTO::ShowMyJob(){
	cout<<Employee::GetName()<<": Manager the project (CTO)!"<<endl;
}

void CTO::Add( Employee* tEmployee ){
	myEmployeeList->push_back(tEmployee);
}

void CTO::Remove( Employee* tEmployee ){
	myEmployeeList->remove(tEmployee);
}

int CTO::GetBonus(){
	return bonus;
}

// Class Programmer
Programmer::Programmer( const char* name, int money ) : 
Employee(name, money){

}

Programmer::~Programmer(){

}

void Programmer::Accept( Visitor& tVisitor ){
	tVisitor.VisitProgrammer(this);
}

void Programmer::ShowMyJob(){
	cout<<Employee::GetName()<<": programming (Programmer)!"<<endl;
}

//class Visitor

Visitor::~Visitor(){

}

Visitor::Visitor(){

}

// class PaymentVisitor

PaymentVisitor::PaymentVisitor() :
				money(0){

}

PaymentVisitor::~PaymentVisitor(){

}

void PaymentVisitor::VisitCEO( CEO* tCEO){
	money += tCEO->GetSalary() + tCEO->GetBonus();
}

void PaymentVisitor::VisitCTO( CTO* tCTO){
	money += tCTO->GetSalary() + tCTO->GetBonus();
}

void PaymentVisitor::VisitSecretary( Secretory* tSecretory){
	money += tSecretory->GetSalary();
}

void PaymentVisitor::VisitProgrammer( Programmer* tProgrammer){
	money += tProgrammer->GetSalary();
}

int PaymentVisitor::GetMoney(){
	return money;
}

void PaymentVisitor::Reset(){
	money = 0;
}

// class JobVisitor
JobVisitor::JobVisitor(){

}

JobVisitor::~JobVisitor(){

}

void JobVisitor::VisitCEO( CEO* tCEO){
	tCEO->ShowMyJob();
}

void JobVisitor::VisitCTO( CTO* tCTO){
	tCTO->ShowMyJob();
}

void JobVisitor::VisitSecretary( Secretory* tSecretory){
	tSecretory->ShowMyJob();
}

void JobVisitor::VisitProgrammer( Programmer* tProgrammer){
	tProgrammer->ShowMyJob();
}