#include <iostream>
#include <string>

//#include "Employee.h"
#include "HourlyEmployee.h"
#include "DB.h"
using namespace std;


int main(){
	srand(time(0));
	DB d(10);
	int i = 1;
	while(i <= 5){
		Employee e;
		Employee* a = &e;
		e.setAllEmployee(a);
		d.insert(e);
	
		HourlyEmployee x;
		HourlyEmployee* k = & x;
		x.setHourlyEmployee(k);
		d.insert(x);
		i++;
	}
	//display the info of the employees
	d.displayEmployees();
	
	//delete 3 employees
	for(int k = 0; k < 3; k++){
		int social = 0;
		cout << "enter the SSN of the employee to be deleted" << endl;
		cin >> social;
		d.remove(social);
	}
	
	//display the info of the employees after deleting 3
	d.displayEmployees();
	
	//reassign the valuse of salary and role for each employee
	d.shuffleSalaries(0.25);
	d.setRoles();
	d.shuffleSalaries(0.25);
	
	//implement copy constructor
	DB d2(d);
	d2.displayEmployees();
	
	// delete one more employee
	for(int k = 0; k < 1; k++){
		int social = 0;
		cout << "enter the SSN of the employee to be deleted" << endl;
		cin >> social;
		d.remove(social);
	}
	
	// implement assignment operator overloading
	d2 = d;
	d2.displayEmployees();
	
	// memory management
	d.~DB();
	d2.~DB();
	
	return 0;
}	
	