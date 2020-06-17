#include <iostream>
#include "Employee.h"
#include <cstdlib>
#include <cstring>

const string Employee::dpt[5] = {"HR", "IT", "PR", "DEV", "MRT"};
int Employee::cntEMP = 0;
int Employee::errA = 0;
int Employee::errB = 0;
int Employee::errC = 0;
int Employee::errD = 0;
int Employee::errE = 0;
int Employee::errF = 0;
int Employee::errG = 0;

Employee::Employee()
{

}

Employee::Employee(string first, string last, int ssn, string dept, double salary, Role role): Employee()
{
    this->firstName = first;
    this->lastName = last;
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
    this->firstName = copy.firstName;
    this->lastName = copy.lastName;
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
    return firstName;
}

string Employee::getLName() const
{
    return lastName;
}

void Employee::setFirstName(string first)
{
	bool isNum = 0;
	for(int i = 0; i < first.length(); i++){
		if(isdigit(first[i]) != 0){
			isNum = 1;
			break;
		}
	}
	try{
		this->firstName = first;
		if(first.length() == 0 || isNum == 1){
			throw 1;
		}
	}
	catch(int n){
		cout << "Name is not valid" << endl;
		++errB;
	}
}

void Employee::setLastName(string last)
{
    
	bool isNum = 0;
	for(int i = 0; i < last.length(); i++){
		if(isdigit(last[i]) != 0){
			isNum = 1;
			break;
		}
	}
	try{
		this->lastName = last;
		if(last.length() == 0 || isNum == 1){
			throw 1;
		}
	}
	catch(int n){
		cout << "Name is not valid" << endl;
		++errB;
	}
}

string Employee::getSSN() const
{
    return SSN;
}

void Employee::setSSN(string ssn)
{
	const int SSN_LENGTH = 9;
	bool isAlpha = 0;
	for(int i = 0; i < ssn.length(); i++){
		if(isalpha(ssn[i] != 0)){
			isAlpha = 1;
			break;
		}
	}
	
	try{
		SSN = ssn;
		if(ssn.length() != SSN_LENGTH || isAlpha == 1){
			throw InvalidSSN();
		}
		
	}
    catch(Employee::InvalidSSN& ){
		cout << "SSN invalid" << endl;
		++errC;
	}
}

string Employee::getDept() const
{
    return department;
}

void Employee::setDept(string dept)
{
	bool match = 0;
	for(int i = 0; i < 5; i++){
		if(dept.compare(dpt[i]) == 0){
			match = 1;
			break;
		}
	}
			
	try{
		this->department = dept;
		if(match != 1){
			throw 'c';
		}
	}
	catch(char n){
		cout <<"Invalid department" << endl;
		++errD;
	}
}

double Employee::getSalary() const
{
    return salary;
}

void Employee::setSalary(double salary)
{
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

/*void Employee::setSalaryM(){
	salary = rand() % (65000 - 45000) + 45000;
}

Role Employee::setRolesM(int r){
	if (r == 1){
		role = programmer;
	}
	if ( r == 2){
		role = manager;
	}
	if ( r == 3){
		role =  director;
	}
	return role;
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
}*/

double Employee::getPayRate(){}

void Employee::setPayRate(double){}

void Employee::setHoursWorked(int){}

void Employee::setBiweeklySalary(){}
