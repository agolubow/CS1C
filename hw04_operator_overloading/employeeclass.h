#ifndef EMPLOYEECLASS_H_
#define EMPLOYEECLASS_H_

#include "hw04.h"
#include "dateclass.h"

class Employee{
public:
	Employee();
	Employee(string,string,string,int,char,string,double,string,string,string);
	~Employee();
	friend bool isSamePhoneNumber(const Employee&,const Employee&);
	friend ostream& operator<<(ostream& os, const Employee& c);
	friend istream& operator>>(istream& is, Employee& s);
	Employee& operator+(int a);
	bool operator==(const Employee&) const;
	bool operator!=(const Employee&) const;
	void setName(string);
	void setId(string);
	void setPhoneNumber(string);
	void setAge(int);
	void setGender(char);
	void setJobTitle(string);
	void setSalary(double);
	void setDate(string,string,string);
	void incrementAge(int);
	string getName() const;
	string getId() const;
	string getPhoneNumber() const;
	int getAge() const;
	char getGender() const;
	string getJobTitle() const;
	double getSalary() const;
	string getHireDate() const;
	virtual void print() const;

private:
	string name;
	string Id;
	string phoneNumber;
	int age;
	char gender;
	string jobTitle;
	double salary;
	Date *hireDate;
};

#endif