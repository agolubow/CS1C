#include "dateclass.h"
#include "hw03.h"

Date::Date(){
	setMonth("01");
	setDay("01");
	setYear("1970");
}

Date::Date(string month,string day,string year){
	this->month = month;
	this->day = day;
	this->year = year;
}

// Date::Date(string date){
// 	string::size_type slash;
// 	string::size_type dash;
// 	slash = date.find_first_of("/",0);
// 	dash = date.find_first_of("-",0);
// 	if(slash != string::npos){
// 		month = date.substr(0,slash);
// 		day = date.substr(slash,(date.find_last_of("/")-1));
// 		year = date.substr(date.find_last_of("/"));
// 	}else if(date != string::npos){
// 		month = date.substr(0,dash);
// 		day = date.substr(dash,(date.find_last_of("-")-1));
// 		year = date.substr(date.find_last_of("-"));
// 	}
// }

void Date::setMonth(string month){
	this->month = month;
}

void Date::setDay(string day){
	this->day = day;
}

void Date::setYear(string year){
	this->year = year;
}

string Date::getMonth() const{
	return month;
}

string Date::getDay() const{
	return day;
}

string Date::getYear() const{
	return year;
}

string Date::getFullDate() const{
	return month+"/"+day+"/"+year;
}