#include <iostream>
#include <iomanip>
#include "Employee.h"
#include "SalariedEmployee.h"

SalariedEmployee::SalariedEmployee():Employee(), biweeklySalary(0.0)
{

}
SalariedEmployee::SalariedEmployee(string first, string last, int ssn, string dept, double salary, Role role, double biweekly) \
            : Employee(first, last, ssn, dept, salary, role)
{
    cout << "HourlyEmployee() with several args called" << endl;
    //In the below, I am showing a different way of initializing non-inherited data fields of HourlyEmployee in the body of the constructor
    biweeklySalary  = biweekly;
    
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

void SalariedEmployee::setAllEmployee(){
	Employee::setAllEmployee();
	setBiweeklySalary();
}

void SalariedEmployee::print(){
	cout << setprecision(2) << fixed;
	cout << setw(10) << getFName(); 
	cout << setw(12) << getLName();
	cout << setw(9) << "S";
	cout<< setw(12) << getSSN() ;
	cout << setw(12) << getDept();
	if (getRole() == 1){
		cout << setw(12) << "programmer";
	}
	if (getRole() == 2){
		cout << setw(12) << "manager";
	}
	if (getRole() == 3){
		cout << setw(12) << "director";
	}
	cout  << setw(21) << getSalary();
	cout << setw(18) << getBiweeklySalary() << endl << endl;
}