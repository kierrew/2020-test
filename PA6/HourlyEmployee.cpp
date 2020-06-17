#include <iostream>
#include "Employee.h"
#include <iomanip>
#include "HourlyEmployee.h"
#include <cstdlib>

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
cntEMP++;
}
HourlyEmployee::HourlyEmployee(string first, string last, int ssn, string dept, double salary, Role role, double rate, int hours) \
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
	salary = -1;
	role = role;
    try{
		payRate = rate;
		
		if(rate > 999){
			throw 1;
		}
	}catch(int x){
		cout << "Pay rate is invalid" << endl;
	}
	try{
		hoursWorked = hours;
		
		if(hours > 50){
			throw 1;
		}
	}catch(int x){
		cout << "Invalid number of hours worked" << endl;
	}
	cntEMP++;
    
}

HourlyEmployee::~HourlyEmployee()
{
    //cout << "~HourlyEmployee() called" << endl;

}

/*HourlyEmployee& HourlyEmployee::operator=(const Employee& copy){
	setFirstName(copy.getFName());
    setLastName(copy.getLName());
    setSSN(copy.getSSN());
    setDept(copy.getDept());
    setSalary(copy.getSalary());
    setRole(copy.getRole());
	this->payRate = 0;
	this->hoursWorked = 0;
	
	return *this;
}*/

//Implement getters and setters
 void HourlyEmployee::setPayRate(HourlyEmployee*& p){
	p->payRate = (rand() % (23 - 7) + 7);
 }
 
 void HourlyEmployee::setPayRate(double pay){
	 try{
		this->payRate = pay;
		if(pay > 999){
			throw 1;
		}
	 }
	 catch(int n){
		 cout <<"Invalid pay rate" << endl;
		 ++errF;
	 }
 }
 
double HourlyEmployee::getPayRate() const{
	return payRate;
}

void HourlyEmployee::setHoursWorked(int hours){
	try{
		this->hoursWorked = hours;
		if(hours > 50){
			throw 8;
		}
	}
	catch(int n){
		cout <<"Invalid hours worked" << endl;
		++errG;
	}
}

int HourlyEmployee::getHoursWorked() const{
	return hoursWorked;
}

/*void HourlyEmployee::setAllEmployee(){
	Employee::setAllEmployee();
	setPayRate();
	setHoursWorked();
}*/

void HourlyEmployee::print(){
	        cout << setw(10) << firstName; 
			cout << setw(12) << lastName;
			cout << setw(9) << "H";
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
			cout  << setw(18) << payRate << "/hr";
			cout << setw(18) << payRate * hoursWorked * 2 << endl;
			cout << "# of Employees " << Employee::cntEMP << endl << endl;
}
			
	