#include <iostream>
#include "Employee.h"


Employee::Employee()
{

}

Employee::Employee(string first, string last, int ssn, string dept, double salary, Role role): Employee()
{
    this->first = first;
    this->last = last;
    SSN = ssn;
    department = dept;
    this->salary = salary;
    this->role = role;
}

Employee::Employee(const Employee& copy)
{
    
    /**
     * Step 1: perform memberwise copy of all non-pointer data fields
     */
    this->first = copy.first;
    this->last = copy.last;
    this->SSN = copy.SSN;
    this->department = copy.department;
    this->salary = copy.salary;
    this->role = copy.role;
    //this->count = copy.count;

    /**
     * Step 2: for the pointer data field, dynamically allocate a memory. 
     *         Then copy one element from the copy to the current object, one at a time.
     */

    /*payStub = new string[12];
    for(int i = 0; i < count; i++)
        payStub[i] = copy.payStub[i];*/
}

/*Employee::~Employee()
{
    delete [] payStub;

}*/


string Employee::getFName() const
{
    return first;
}

string Employee::getLName() const
{
    return last;
}

void Employee::setFirstName(string first)
{
    this->first = first;
}

void Employee::setLastName(string last)
{
    this->last = last;
}

int Employee::getSSN() const
{
    return SSN;
}

void Employee::setSSN(int ssn)
{
    SSN = ssn;
}

string Employee::getDept() const
{
    return department;
}

void Employee::setDept(string dept)
{
    this->department = dept;
}

double Employee::getSalary() const
{
    return salary;
}

void Employee::setSalary(double salary)
{
    this->salary = salary;
}

Role Employee::getRole() const
{
    return role;
}

void Employee::setRole(Role role)
{
    this->role = role;
}

//void Employee::directDeposit(string ps)
//{
   // if (count == 12) {
     //   cout << "error: a direct deposit" << endl;
       // return;
  //  }

    //Note : the following code is executed only when count < 12
    //payStub[count] = ps;
    //count++;

//}

/*void Employee::displayPayStub() const
{
    cout << "== Pay Stub == " << endl;
    for(int i = 0; i < count; i++)
        cout << payStub[i] << endl;

}*/

void Employee::setSalaryM(){
	salary = rand() % (65000 - 45000) + 45000;
}

void Employee::setRolesM(){
	int i = rand() % 3 +1;
	if (i == 1){
		role = programmer;
	}
	if ( i == 2){
		role = manager;
	}
	if ( i == 3){
		role =  director;
	}
}

//sets the SSN of the employee
void Employee::setSSNM(){
	SSN = rand() % (900000000 - 100000000) + 100000000;
}

//sets the first name of each employee
void Employee::setFName(){
	string Name[6] = {"Matt", "Steven", "Jessica", "Amy", "Robert", "Kim"};
	int i = rand() % 6;
	first = Name[i];
}

//set the last name of each employee
void Employee::setLName(){
	 string Name[6] = {"Brown", "Smith", "Maker", "Schumer", "Lopez", "Alvarez"};
        int i = rand() % 6;
        last = Name[i];
}

// sets the department of each employee
void Employee::setDepartmentM(){
	string Dept[5] = {"IT", "Sales", "HR", "Logistics", "Analyitics"};
    int i = rand() % 5;
    department = Dept[i];
}

//uses previous functions to assing all employee variables at once		
void Employee::setAllEmployee(){
	setRolesM();
	setSSNM();
	setFName();
	setLName();
	setDepartmentM();
	setSalaryM();
}

double Employee::getPayRate(){}

