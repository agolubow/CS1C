#ifndef SOFTWAREARCHITECT_H_
#define SOFTWAREARCHITECT_H_

#include "employeeclass.h"

class SoftwareArchitect:public Employee{
public:
	SoftwareArchitect();
	SoftwareArchitect(string,string,string,int,char,string,double,string,string,string,string,string,double,int);
	void setDepartmentNumber(string);
	void setSupervisorName(string);
	void setPercentageIncrease(double);
	void setExperience(int);
	string getDepartmentNumber() const;
	string getSupervisorName() const;
	double getPercentageIncrease() const;
	int getExperience() const;
	void print() const;
private:
	string departmentNumber;
	string supervisorName;
	double percentageIncrease;
	int yearsOfExperience;
};

#endif