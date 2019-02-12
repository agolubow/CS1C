#ifndef PROGRAMMERCLASS_H_
#define PROGRAMMERCLASS_H_

#include "employeeclass.h"

class Programmer:public Employee{
public:
	Programmer();
	Programmer(string,string,string,int,char,string,double,string,string,string,string,string,double,bool,bool);
	void setDepartmentNumber(string);
	void setSupervisorName(string);
	void setPercentageIncrease(double);
	void setKnowsCPP(bool);
	void setKnowsJAVA(bool);
	string getDepartmentNumber() const;
	string getSupervisorName() const;
	double getPercentageIncrease() const;
	bool getKnowsCPP() const;
	bool getKnowsJAVA() const;
	void print() const;

private:
	string departmentNumber;
	string supervisorName;
	double percentageIncrease;
	bool knowsCPP;
	bool knowsJAVA;
};

#endif