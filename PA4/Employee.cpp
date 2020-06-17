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

Employee& Employee::operator=(const Employee& copy)
{
    
    /**
     * Note1: The structure of the following code is a typical Implementation 
     *      when a class has one or two data fields like the DB class
     *
     * Note 2: Though the Employee has several fields, I am presenting the typical implementation of operator=()
     *     so that you can use this method for the project.
     */
    
    /** Below is the structure of a typical implementation of operator=().
     *  Step 1: perform memberwise copy for all non-pointer data fields
     *        Carefully observe that, in the member function of Employee, 
     *        it can directly access private members of any Employee object available in that memeber function
     */ 
    this->first = copy.first;
    this->last = copy.last;
    this->SSN = copy.SSN;
    this->department = copy.department;
    this->salary = copy.salary;
    this->role = copy.role;

    /**
     * Step 2: create a local object that is a duplicate of the existing object, copy, 
     *          by using the copy constructor
     */

    Employee local(copy);

    /**
     * Step 3: swap pointer data fields of the local object and the current object that calls operator=().
     */
  /*  string *temp = local.payStub;
    local.payStub = this->payStub;
    this->payStub = temp;
    */
     
    /**
     * Step 4: return *this and make sure the return type of operator=() has &
     */

    return *this;

}

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

void Employee::setSalaryM(Employee*& p){
	p->salary = rand() % (65000 - 45000) + 45000;
}

void Employee::setRolesM(Employee*& p){
	int i = rand() % 3 +1;
	if (i == 1){
		p->role = programmer;
	}
	if ( i == 2){
		p->role = manager;
	}
	if ( i == 3){
		p->role =  director;
	}
}

//sets the SSN of the employee
void Employee::setSSNM(Employee*& p){
	p->SSN = rand() % (900000000 - 100000000) + 100000000;
}

//sets the first name of each employee
void Employee::setFName(Employee*& p){
	string Name[6] = {"Matt", "Steven", "Jessica", "Amy", "Robert", "Kim"};
	int i = rand() % 6;
	p->first = Name[i];
}

//set the last name of each employee
void Employee::setLName(Employee*& p){
	 string Name[6] = {"Brown", "Smith", "Maker", "Schumer", "Lopez", "Alvarez"};
        int i = rand() % 6;
        p->last = Name[i];
}

// sets the department of each employee
void Employee::setDepartmentM(Employee*& p){
	string Dept[5] = {"IT", "Sales", "HR", "Logistics", "Analyitics"};
    int i = rand() % 5;
    p->department = Dept[i];
}

//uses previous functions to assing all employee variables at once		
void Employee::setAllEmployee(Employee*& p){
	setRolesM(p);
	setSSNM(p);
	setFName(p);
	setLName(p);
	setDepartmentM(p);
	setSalaryM(p);
}


