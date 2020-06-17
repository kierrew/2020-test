/*PA2
Kierre Willoughby
9/17/19
this program fills the data types of employee structs and organize them in a singly linked list*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "Employee.h"
#include "Node.h"
using namespace std;

void getEmployee(Employee*& p);
void setSalaries(Employee*& p);
void setRoles(Employee*& p);
void setSSN(Employee*& p);
void setFName(Employee*& p);
void setLName(Employee*& p);
void setDepartment(Employee*& p);

int main(){
	srand(time(0));
	
	Node* head = NULL;
	Node* prev = NULL;
	Node* next = NULL;
	Employee e;
	double sal = 0;
	int count = 0;
	int cp = 0;
	int cm = 0;
	int cd = 0;

	//1. create a linked list of employees
        for(int i = 0; i < 10; i++) {
		Employee e;
		Employee* p = &e;
        	getEmployee(p);
        	Node* temp = new Node(e);
        	if(i == 0) { 
        		head = temp;
        		prev = head;
        	}	
        	else {
            		prev->next = temp;
            		prev = temp;
        	}
	}
	// make table for programmer info, calculate average salary, and count the number of each role
	cout << "FIRST NAME   LAST NAME         SSN  DEPARTMENT        ROLE      SALARY    " << endl;
	cout << endl;
	prev = head;
 	while(prev != NULL) {
        	cout << setprecision(2) << fixed;
		cout << setw(10) << (prev->e).firstName << setw(12) << (prev->e).lastName << setw(12) << (prev->e).SSN<< setw(12) << (prev->e).department;
		if ((prev->e).role == 1){
			cout << setw(12) << "programmer";
			cp++;
		}
		if ((prev->e).role == 2){
			cout << setw(12) << "manager";
			cm++;
		}
		if ((prev->e).role == 3){
			cout << setw(12) << "director";
			cd++;
		}
		cout  << setw(12) << (prev->e).salary << endl << endl;
                sal += (prev->e).salary;
                count++;
		prev = prev-> next;
	}
	cout << endl;
	cout << "The average salary = " << (sal/count) << endl << endl;
	cout << "The number of programmers is " << cp << endl;
	cout << "The number of managers is " << cm << endl;
	cout << "The number of directors is " << cd << endl;
	sal = 0;
	count = 0;
	
	// make table for programmer info and calculate average salary
	cout << "FIRST NAME   LAST NAME         SSN  DEPARTMENT        ROLE      SALARY    " << endl;
	cout << endl;
	prev = head;
        while(prev != NULL) {
		if ((prev->e).role == 1){
                	cout << setprecision(2) << fixed;
                	cout << setw(10) << (prev->e).firstName << setw(12) << (prev->e).lastName << setw(12) << (prev->e).SSN<< setw(12) << (prev->e).department;
                	if ((prev->e).role == 1){
                        	cout << setw(12) << "programmer";
                        	cp++;
                	}
                	if ((prev->e).role == 2){
                        	cout << setw(12) << "manager";
                        	cm++;
                }
                	if ((prev->e).role == 3){
                        	cout << setw(12) << "director";
                        	cd++;
                	}
                	cout  << setw(12) << (prev->e).salary << endl << endl;
                	sal += (prev->e).salary;
                	count++;
		}
                prev = prev-> next;	
		
	}
	cout << "The average salary of the programmers = " << (sal/count) << endl << endl;
	
	// memoery management
	prev = head; 
        while(prev != NULL) {
		next = prev-> next;
		delete prev;
		prev = next;
	}
	head = NULL;
        prev = NULL;
        next = NULL;
	return 0;
}

void setSalary(Employee*& p){
	p->salary = rand() % (65000 - 45000) + 45000;
}

void setRoles(Employee*& p){
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

void setSSN(Employee*& p){
	p->SSN = rand() % (900000000 - 100000000) + 100000000;
}

void setFName(Employee*& p){
	string Name[6] = {"Matt", "Steven", "Jessica", "Amy", "Robert", "Kim"};
	int i = rand() % 6;
	p->firstName = Name[i];
}

void setLName(Employee*& p){
	 string Name[6] = {"Brown", "Smith", "Maker", "Schumer", "Lopez", "Alvarez"};
        int i = rand() % 6;
        p->lastName = Name[i];
}

void setDepartment(Employee*& p){
	 string Dept[5] = {"IT", "Sales", "HR", "Logistics", "Analyitics"};
        int i = rand() % 5;
        p->department = Dept[i];
}

void getEmployee(Employee*& p){
	setSalary(p);
	setRoles(p);
	setSSN(p);
	setFName(p);
	setLName(p);
	setDepartment(p);
}
