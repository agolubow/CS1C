#include "softwarearchitectclass.h"
#include "hw03.h"

SoftwareArchitect::SoftwareArchitect(){
	setDepartmentNumber("BLANK");
	setSupervisorName("BLANK");
	setPercentageIncrease(0.00);
	setExperience(0);
}
SoftwareArchitect::SoftwareArchitect(string name,string Id,string phoneNumber,int age,char gender,string jobTitle,double salary,string hireDay,string hireMonth,string hireYear,string deptNum,string supName,double percentage,int experience):Employee(name,Id,phoneNumber,age,gender,jobTitle,salary,hireDay,hireMonth,hireYear){
	setDepartmentNumber(deptNum);
	setSupervisorName(supName);
	setPercentageIncrease(percentage);
	setExperience(experience);
}

void SoftwareArchitect::setDepartmentNumber(string number){
	departmentNumber = number;
}
void SoftwareArchitect::setSupervisorName(string name){
	supervisorName = name;
}
void SoftwareArchitect::setPercentageIncrease(double percentage){
	percentageIncrease = percentage;
}
void SoftwareArchitect::setExperience(int years){
	yearsOfExperience = years;
}
string SoftwareArchitect::getDepartmentNumber() const{
	return departmentNumber;
}
string SoftwareArchitect::getSupervisorName() const{
	return supervisorName;
}
double SoftwareArchitect::getPercentageIncrease() const{
	return percentageIncrease;
}
int SoftwareArchitect::getExperience() const{
	return yearsOfExperience;
}
void SoftwareArchitect::print() const{
	Employee::print();
	cout <<setw(21)<<left<<"Department Number:"<<getDepartmentNumber()<<endl
		<<setw(21)<<"Supervisor Name:"<<getSupervisorName()<<endl
		<<setw(21)<<"Salary Increase (%):"<<getPercentageIncrease()<<"%"<<endl
		<<setw(21)<<"Years of Experience:"<<getExperience()<<endl<<endl;
}