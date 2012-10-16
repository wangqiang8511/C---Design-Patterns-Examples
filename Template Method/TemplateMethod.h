/**
*	Template Method
*
*	This simple example is used to show how template method works.
*	This example simulate the the process of EEG data.
*
*	Wang Qiang @NTU 2010
*/

#include <iostream>
using namespace std;

class EEGAlgorithm{
public:
	EEGAlgorithm();
	virtual ~EEGAlgorithm();
	virtual void EEGDataProcess();			// Template Method
protected:
	virtual void EEGDataRead();				// Primitive Method
	virtual void EEGFDCalculation();		// Primitive Method
	virtual void EEGDeviceClose();			// Primitive Method
};


class HiguchiAlgorithm : public EEGAlgorithm{
public:
	HiguchiAlgorithm();
	virtual ~HiguchiAlgorithm();
protected:
	virtual void EEGFDCalculation();
};

class BoxcountingAlgorithm : public EEGAlgorithm{
public:
	BoxcountingAlgorithm();
	virtual ~BoxcountingAlgorithm();
protected:
	virtual void EEGFDCalculation();
};