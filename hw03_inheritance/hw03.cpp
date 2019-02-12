#include "programmerclass.h"
#include "softwarearchitectclass.h"
#include "employeeclass.h"
#include "hw03.h"

int main(){

	Employee employee1;
	Programmer programmer1;
	SoftwareArchitect architect1;

	employee1.setName("Stephan Colbert");
	employee1.setId("12346");
	employee1.setPhoneNumber("310-555-5555");
	employee1.setAge(51);
	employee1.setGender('M');
	employee1.setJobTitle("Comedian");
	employee1.setSalary(70123);
	employee1.setDate("05","08","2015");

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

	cout<<"-----------Employee One-----------"<<endl<<endl;
	employee1.print();
	cout<<"-----------Programmer One-----------"<<endl<<endl;
	programmer1.print();
	cout<<"-----------Architect One-----------"<<endl<<endl;
	architect1.print();

	cout<<"-----------Employee Two-----------"<<endl<<endl;
	employee2.print();
	cout<<"-----------Programmer Two-----------"<<endl<<endl;
	programmer2.print();
	cout<<"-----------Architect Two-----------"<<endl<<endl;
	architect2.print();

	cout<<"-----------Employee Two Modified-----------"<<endl<<endl;
	employee2.setJobTitle("Dancer");
	employee2.setPhoneNumber("111-111-1111");
	employee2.setSalary(1.52);
	employee2.print();
	cout<<"-----------Programmer Two Modified-----------"<<endl<<endl;
	double newSalary = (programmer2.getSalary()*programmer2.getPercentageIncrease());
	programmer2.setSalary(newSalary);
	programmer2.setKnowsJAVA(false);
	programmer2.setSupervisorName("Joe Boss");
	programmer2.print();
	cout<<"-----------Architect Two Modified-----------"<<endl<<endl;
	double newerSalary = (architect2.getSalary()*architect2.getPercentageIncrease());
	architect2.setSalary(newerSalary);
	architect2.setSupervisorName("Mary Leader");
	architect2.setExperience(7);
	architect2.print();

	return 0;
}