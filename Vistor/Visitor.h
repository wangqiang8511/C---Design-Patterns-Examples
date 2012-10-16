/**
*	Visitor Pattern
*
*	This example is used for showing how visitor pattern works.
*	The simple example simulate the composite for employee system.
*   A visitor used for calculating the salary is implemented.
*
*	Wang Qiang @NTU 2010
*/

#include <iostream>
#include <list>
using namespace std;


class Visitor;


// Composite structure
class Employee{
public:
	virtual ~Employee();
	virtual void Accept(Visitor& tVisitor) = 0;
	virtual void ShowMyJob() = 0;
	virtual void Add(Employee* tEmployee);
	virtual void Remove(Employee* tEmployee);
	int GetSalary();
	const char* GetName();
protected:
	Employee(const char* name, int money);
private:
	const char* myName;
	int salary;
};

class CEO : public Employee{
public:
	CEO(const char* name, int money, int tbonus);
	virtual ~CEO();
	virtual void Accept(Visitor& tVisitor);
	virtual void ShowMyJob();
	virtual void Add(Employee* tEmployee);
	virtual void Remove(Employee* tEmployee);
	int GetBonus();
	int CalculateSalary();
	void ListJob();
private:
	int bonus;
	list<Employee*>* myEmployeeList;
};

class Secretory : public Employee{
public:
	Secretory(const char* name, int money);
	virtual ~Secretory();
	virtual void Accept(Visitor& tVisitor);
	virtual void ShowMyJob();
};

class CTO : public Employee{
public:
	CTO(const char* name, int money, int bonus);
	virtual ~CTO();
	virtual void Accept(Visitor& tVisitor);
	virtual void ShowMyJob();
	virtual void Add(Employee* tEmployee);
	virtual void Remove(Employee* tEmployee);
	int GetBonus();
private:
	int bonus;
	list<Employee*>* myEmployeeList;
};

class Programmer : public Employee{
public:
	Programmer(const char* name, int money);
	virtual ~Programmer();
	virtual void Accept(Visitor& tVisitor);
	virtual void ShowMyJob();
};

// Class Visitor
class Visitor{
public:
	virtual ~Visitor();
	virtual void VisitCEO(CEO*) = 0;
	virtual void VisitCTO(CTO*) = 0;
	virtual void VisitSecretary(Secretory*) = 0;
	virtual void VisitProgrammer(Programmer*) = 0;
protected:
	Visitor();
};

// Concrete Visitor
class PaymentVisitor : public Visitor{
public:
	PaymentVisitor();
	virtual ~PaymentVisitor();
	virtual void VisitCEO(CEO*);
	virtual void VisitCTO(CTO*);
	virtual void VisitSecretary(Secretory*);
	virtual void VisitProgrammer(Programmer*);
	int GetMoney();
	void Reset();
private:
	int money;
};

class JobVisitor : public Visitor{
public:
	JobVisitor();
	virtual ~JobVisitor();
	virtual void VisitCEO(CEO*);
	virtual void VisitCTO(CTO*);
	virtual void VisitSecretary(Secretory*);
	virtual void VisitProgrammer(Programmer*);
};