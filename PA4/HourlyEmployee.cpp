#include <iostream>
#include "Employee.h"
#include "HourlyEmployee.h"

/**
 * Note: The member functions of a child class cannot directly access the private memebers of its parent class,
         though they are inherited by the child class but they are hidden data fields from the child class' point of view
 *       Direct access means using . or -> to access a data field.
 *       The only way in which a member function of the child class to manipulate the inherited data fields is to use
 *       public or protected member functions of the parent class.
 *       You do not need to know the keyword, protected, at this moment.
 *
 */
HourlyEmployee::HourlyEmployee():Employee(), payRate(0.0), hoursWorked(-1)
{

}
HourlyEmployee::HourlyEmployee(string first, string last, int ssn, string dept, double salary, Role role, double rate, int hours) \
            : Employee(first, last, ssn, dept, salary, role)
{
    cout << "HourlyEmployee() with several args called" << endl;
    //In the below, I am showing a different way of initializing non-inherited data fields of HourlyEmployee in the body of the constructor
    payRate = rate;
    hoursWorked = hours;
    
}

HourlyEmployee::~HourlyEmployee()
{
    //cout << "~HourlyEmployee() called" << endl;

}

HourlyEmployee& HourlyEmployee::operator=(const Employee& copy){
	setFirstName(copy.getFName());
    setLastName(copy.getLName());
    setSSN(copy.getSSN());
    setDept(copy.getDept());
    setSalary(copy.getSalary());
    setRole(copy.getRole());
	this->payRate = 0;
	this->hoursWorked = 0;
	
	return *this;
}

//Implement getters and setters
 void HourlyEmployee::setPayRate(HourlyEmployee*& p){
	p->payRate = (rand() % (23 - 7) + 7);
 }
 
 void HourlyEmployee::setPayRate(double pay){
	 payRate = pay;
 }
 
double HourlyEmployee::getPayRate() const{
	return payRate;
}

void HourlyEmployee::setHoursWorked(HourlyEmployee*& p){
	p->hoursWorked = (rand() % (40) + 1);
}

int HourlyEmployee::getHoursWorked() const{
	return hoursWorked;
}

void HourlyEmployee::setRolesH(HourlyEmployee*& p){
	int i = rand() % 3 +1;
	if (i == 1){
		setRole(programmer);
	}
	if ( i == 2){
		setRole(manager);
	}
	if ( i == 3){
		setRole(director);
	}
}

//sets the SSN of the employee
void HourlyEmployee::setSSNH(HourlyEmployee*& p){
	setSSN(rand() % (900000000 - 100000000) + 100000000);
}

//sets the first name of each employee
void HourlyEmployee::setFNameH(HourlyEmployee*& p){
	string Name[6] = {"Matt", "Steven", "Jessica", "Amy", "Robert", "Kim"};
	int i = rand() % 6;
	setFirstName(Name[i]);
}

//set the last name of each employee
void HourlyEmployee::setLNameH(HourlyEmployee*& p){
	 string Name[6] = {"Brown", "Smith", "Maker", "Schumer", "Lopez", "Alvarez"};
        int i = rand() % 6;
        setLastName(Name[i]);
}

// sets the department of each employee
void HourlyEmployee::setDepartmentH(HourlyEmployee*& p){
	string Dept[5] = {"IT", "Sales", "HR", "Logistics", "Analyitics"};
    int i = rand() % 5;
    setDept(Dept[i]);
}

void HourlyEmployee::setHourlyEmployee(HourlyEmployee*& p){
	setRolesH(p);
	setSSNH(p);
	setFNameH(p);
	setLNameH(p);
	setDepartmentH(p);
	setPayRate(p);
	setSalary(-1);
	setHoursWorked(p);
}	 