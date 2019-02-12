#include "employeeclass.h"
#include "hw03.h"

Employee::Employee(){
	setName("BLANK");
	setId("BLANK");
	setPhoneNumber("BLANK");
	setAge(0);
	setGender('X');
	setJobTitle("BLANK");
	setSalary(0.00);
	setDate("00","00","00");
}
Employee::Employee(string name,string Id,string phoneNumber,int age,char gender,string jobTitle,double salary,string hireDay, string hireMonth, string hireYear){
	setName(name);
	setId(Id);
	setPhoneNumber(phoneNumber);
	setAge(age);
	setGender(gender);
	setJobTitle(jobTitle);
	setSalary(salary);
	setDate(hireDay,hireMonth,hireYear);
}
Employee::~Employee(){
	delete hireDate;
}
void Employee::setName(string n){
	name = n;
}
void Employee::setId(string I){
	Id = I;
}
void Employee::setPhoneNumber(string phoneNumber){
	this->phoneNumber = phoneNumber;
}
void Employee::setAge(int age){
	this->age = age;
}
void Employee::setGender(char g){
	gender = g;
}
void Employee::setJobTitle(string jobTitle){
	this->jobTitle = jobTitle;
}
void Employee::setSalary(double salary){
	this->salary = salary;
}
void Employee::setDate(string hireDay, string hireMonth, string hireYear){
	hireDate = new Date(hireDay,hireMonth,hireYear);
}
string Employee::getName() const{
	return name;
}
string Employee::getId() const{
	return Id;
}
string Employee::getPhoneNumber() const{
	return phoneNumber;
}
int Employee::getAge() const{
	return age;
}
char Employee::getGender() const{
	return gender;
}
string Employee::getJobTitle() const{
	return jobTitle;
}
double Employee::getSalary() const{
	return salary;
}
string Employee::getHireDate() const{
	return hireDate->getFullDate();
}
void Employee::print() const{
	cout <<setw(21)<<left<<"Name:"<<getName()<<endl
		<<setw(21)<<"Id #:"<<getId()<<endl
		<<setw(21)<<"Phone Number:"<<getPhoneNumber()<<endl
		<<setw(21)<<"Age:"<<getAge()<<endl
		<<setw(21)<<"Gender:"<<getGender()<<endl
		<<setw(21)<<"Job Title:"<<getJobTitle()<<endl
		<<setw(21)<<"Salary:"<<"$"<<getSalary()<<endl
		<<setw(21)<<"Hire Date:"<<getHireDate()<<endl<<endl;
}