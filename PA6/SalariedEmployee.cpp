#include <iostream>
#include <iomanip>
#include "Employee.h"
#include "SalariedEmployee.h"
#include <cstdlib>

SalariedEmployee::SalariedEmployee():Employee(), biweeklySalary(0.0)
{
cntEMP++;
}
SalariedEmployee::SalariedEmployee(string first, string last, int ssn, string dept, double salary, Role role) 
{
	try{
		firstName = first;
		
		if(first.empty()){
			throw 1;
		}
	}catch(int x){
		cout <<"Name is empty" << endl;
	}
	try{
		lastName = last;
		
		if(last.empty()){
			throw 1;
		}
	}catch(int x){
		cout <<"Name is empty" << endl;
	}
	try{
		SSN = ssn;
		
		if(ssn < 100000000 || ssn > 999999999){
			throw 1;
		}
	}
	catch(int x){
		cout << "SSN is invalid" << endl;
	}
	try{
		department = dept;
		if(dept != dpt[0] && dept != dpt[1] && dept != dpt[2] && dept != dpt[3] && dept != dpt[4]){
			throw 1;
		}
	}catch(int x){
		cout << "Not valid department" << endl;
	}
	try{
		salary = salary;
		
		if(salary < 10000 || salary > 9999999){
			throw 1;
		}
	}catch(int x){
		cout << "Invalid salary" << endl;
	}
	role = role;
    setBiweeklySalary();
    cntEMP++;
}

SalariedEmployee::~SalariedEmployee()
{
    //cout << "~HourlyEmployee() called" << endl;

}

void SalariedEmployee::setBiweeklySalary(){
	biweeklySalary = (getSalary() / 52) * 2;
}

double SalariedEmployee::getBiweeklySalary() const{
	return biweeklySalary;
}

/*void SalariedEmployee::setAllEmployee(){
	Employee::setAllEmployee();
	setBiweeklySalary();
}*/

void SalariedEmployee::setSalary(double salary){
	try{
		this->salary = salary;
		if(salary < 10000 || salary > 9999999){
			throw 2.2;
		}
	}
	catch(double x){
		cout <<"Invalid salary" << endl;
		++errE;
	}
}

void SalariedEmployee::print(){
	cout << setprecision(2) << fixed;
	cout << setw(10) << firstName; 
	cout << setw(12) << lastName;
	cout << setw(9) << "S";
	cout<< setw(12) << SSN;
	cout << setw(12) << department;
	if (role == 1){
		cout << setw(12) << "programmer";
	}
	if (role == 2){
		cout << setw(12) << "manager";
	}
	if (role == 3){
		cout << setw(12) << "director";
	}
	cout  << setw(21) << salary;
	cout << setw(18) << biweeklySalary << endl;
	cout << "# of Employees " << Employee::cntEMP << endl << endl;
}