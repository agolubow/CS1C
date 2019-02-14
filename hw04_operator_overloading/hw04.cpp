#include "programmerclass.h"
#include "softwarearchitectclass.h"
#include "employeeclass.h"
#include "hw04.h"

int main(){

	Employee employee1;
	Programmer programmer1;
	SoftwareArchitect architect1;

	programmer1.setName("Sam Software");
	programmer1.setId("54321");
	programmer1.setPhoneNumber("819-123-4567");
	programmer1.setAge(21);
	programmer1.setGender('M');
	programmer1.setJobTitle("Programmer");
	programmer1.setSalary(223000);
	programmer1.setDate("12","24","2011");
	programmer1.setDepartmentNumber("5432122");
	programmer1.setSupervisorName("Joe Boss");
	programmer1.setPercentageIncrease(4.00);
	programmer1.setKnowsCPP(true);
	programmer1.setKnowsJAVA(false);

	architect1.setName("Alex Arch");
	architect1.setId("88888");
	architect1.setPhoneNumber("819-123-4444");
	architect1.setAge(31);
	architect1.setGender('M');
	architect1.setJobTitle("Architect");
	architect1.setSalary(323000);
	architect1.setDate("12","24","2009");
	architect1.setDepartmentNumber("5434222");
	architect1.setSupervisorName("Big Boss");
	architect1.setPercentageIncrease(5.00);
	architect1.setExperience(4);

	Employee employee2("James Corden","87654","703-703-1234",37,'M',"Talk Show Host",900000,"12","25","2014");
	Programmer programmer2("Mary Coder","65432","310-555-5555",28,'F',"Programmer",770123,"02","08","2010","6543222","Mary Leader",7.00,true,true);
	SoftwareArchitect architect2("Sally Designer","87878","310-555-8888",38,'F',"Architect",870123,"02","08","2003","6543422","Big Boss",8.00,11);

	cout <<"-----------Before Change (friend function compare)-----------"<<endl<<endl;
	if(isSamePhoneNumber(employee2,programmer2)){
		cout <<"Phone numbers are identical!"<<endl<<endl;
	}else{
		cout <<"Phone numbers are different!"<<endl<<endl;
	}

	employee2.setPhoneNumber(programmer2.getPhoneNumber());
	cout <<"-----------After Change (friend function compare)-----------"<<endl<<endl;

	if(isSamePhoneNumber(employee2,programmer2)){
		cout <<"Phone numbers are identical!"<<endl<<endl;
	}else{
		cout <<"Phone numbers are different!"<<endl<<endl;
	}
	cout <<"-----------Stream operator test-----------"<<endl<<endl;
	cout <<"Enter employee1 information: ";
	cin >>employee1;
	cout<<endl<<"-----------Employee One-----------"<<endl<<endl;
	cout << employee1;

	cout <<"-----------Before Change (employee1 == employee2)-----------"<<endl<<endl;
	if(employee1 == employee2){
		cout <<"Phone numbers are identical!"<<endl<<endl;
	}else{
		cout <<"Phone numbers are different!"<<endl<<endl;
	}

	employee1.setPhoneNumber(employee2.getPhoneNumber());

	cout <<"-----------After Change (employee1 == employee2)-----------"<<endl<<endl;
	if(employee1 == employee2){
		cout <<"Phone numbers are identical!"<<endl<<endl;
	}else{
		cout <<"Phone numbers are different!"<<endl<<endl;
	}

	cout<<"-----------Before increment age-----------"<<endl<<endl;
	cout << employee2<<endl;

	employee2.incrementAge(6);

	cout<<"-----------After increment age-----------"<<endl<<endl;
	cout<<employee2<<endl;

	employee2 = employee2 + 2;
	cout<<"-----------After adding age (addition operator)-----------"<<endl<<endl;

	cout<<employee2<<endl;

	return 0;
}