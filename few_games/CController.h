#ifndef CCONTROLLER_H
#define CCONTROLLER_H

class CController
{
protected:
	virtual void Controller();

	virtual void ProcessingUP() = 0;
	virtual void ProcessingDOWN() = 0;
	virtual void ProcessingLEFT() = 0;
	virtual void ProcessingRIGHT() = 0;
	virtual void ProcessingESCAPE() = 0;
	virtual void ProcessingSPACE() = 0;
	virtual void ProcessingRETURN() = 0;
public:
	CController() = default;
	virtual ~CController() = default;
};

#endif CCONTROLLER_H