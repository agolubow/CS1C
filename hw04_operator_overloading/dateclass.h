#ifndef DATECLASS_H_
#define DATECLASS_H_

#include "hw04.h"

class Date{

public:
	Date();
	Date(string,string,string);
	//Date(string);
	void setMonth(string);
	void setDay(string);
	void setYear(string);
	string getMonth() const;
	string getDay() const;
	string getYear() const;
	string getFullDate() const;
private:
	string month;
	string day;
	string year;
};

#endif