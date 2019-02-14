#include "programmerclass.h"
#include "hw04.h"

Programmer::Programmer(){
	setDepartmentNumber("BLANK");
	setSupervisorName("BLANK");
	setPercentageIncrease(0.00);
	setKnowsCPP(false);
	setKnowsJAVA(false);
}
Programmer::Programmer(string name,string Id,string phoneNumber,int age,char gender,string jobTitle,double salary,string hireDay,string hireMonth,string hireYear,string deptNum,string supName,double percentage,bool knowCPP,bool knowJAVA):Employee(name,Id,phoneNumber,age,gender,jobTitle,salary,hireDay,hireMonth,hireYear){
	setDepartmentNumber(deptNum);
	setSupervisorName(supName);
	setPercentageIncrease(percentage);
	setKnowsCPP(knowCPP);
	setKnowsJAVA(knowJAVA);
}
void Programmer::setDepartmentNumber(string number){
	departmentNumber = number;
}
void Programmer::setSupervisorName(string name){
	supervisorName = name;
}
void Programmer::setPercentageIncrease(double percentage){
	percentageIncrease = percentage;
}
void Programmer::setKnowsCPP(bool knows){
	knowsCPP = knows;
}
void Programmer::setKnowsJAVA(bool knows){
	knowsJAVA = knows;
}
string Programmer::getDepartmentNumber() const{
	return departmentNumber;
}
string Programmer::getSupervisorName() const{
	return supervisorName;
}
double Programmer::getPercentageIncrease() const{
	return percentageIncrease;
}
bool Programmer:: getKnowsCPP() const{
	return knowsCPP;
}
bool Programmer::getKnowsJAVA() const{
	return knowsJAVA;
}
void Programmer::print() const{
	string knowscpp = getKnowsCPP()?"True":"False";
	string knowsJava = getKnowsJAVA()?"True":"False";
	Employee::print();
	cout <<setw(21)<<left<<"Department Number:"<<getDepartmentNumber()<<endl
		<<setw(21)<<"Supervisor Name:"<<getSupervisorName()<<endl
		<<setw(21)<<"Salary Increase (%):"<<getPercentageIncrease()<<"%"<<endl
		<<setw(21)<<"Knows C++:"<<knowscpp<<endl
		<<setw(21)<<"Knows Java:"<<knowsJava<<endl<<endl;
}