#include <iostream>
#include "Employee.h"
#include <iomanip>
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
 
 void HourlyEmployee::setPayRate(){
	 payRate = (rand() % (23 - 7) + 7);
 }
 
double HourlyEmployee::getPayRate() const{
	return payRate;
}

void HourlyEmployee::setHoursWorked(){
	hoursWorked = (rand() % (40) + 1);
}

int HourlyEmployee::getHoursWorked() const{
	return hoursWorked;
}

void HourlyEmployee::setAllEmployee(){
	Employee::setAllEmployee();
	setPayRate();
	setHoursWorked();
}

void HourlyEmployee::print(){
	        cout << setw(10) << getFName(); 
			cout << setw(12) << getLName();
			cout << setw(9) << "H";
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
			cout  << setw(18) << getPayRate() << "/hr";
			cout << setw(18) << getPayRate() * getHoursWorked() * 2 << endl << endl;
}
			
	