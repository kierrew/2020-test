#include "DB.h"
#include <iomanip>
#include <iostream>
using namespace std;

//constructor
DB::DB(int s){
	count = s;
	head = NULL;
	current = head;
	temp = head;
	
}

//destructor
DB::~DB(){
	current = head;
	while(current != NULL) {
		current = head->next;
		delete head;
		head = current;
	}
	head = NULL;
        current = NULL;
        temp = NULL;
}

DB::DB(const DB& copy){
	this->count = copy.count;
	head = NULL;
	current = head;
	temp = head;
	Node* n = copy.head;
	while(n != NULL){
		insert(n->e);
		n = n->next;
	}
}

DB& DB::operator=(const DB& copy){
	this->count = copy.count;
	this->~DB();
	head = NULL;
	current = head;
	temp = head;
	
	Node* n = copy.head;
	while(n != NULL){
		insert(n->e);
		n = n->next;
	}
	return *this;
}

//insterts employees int the database
void DB::insert(HourlyEmployee& e){
	if(head == NULL){
		head = new Node;
		current = head;
		current->e = e;
	}
	else{
		temp = new Node;
		temp->next = head;
		head = temp;
		head->e = e;
	}
}

void DB::insert(Employee& e){
	if(head == NULL){
		head = new Node;
		current = head;
		current->e = e;
	}
	else{
		temp = new Node;
		current->next = temp;
		current = temp;
		current->e = e;
	}
}

//delete the employees from the database
void DB::remove(int social){
	temp = head->next;
	current = head; 
	int x;
	x = getSize();
	if(social == (head->e).getSSN()){
		delete head;
		head = temp;
		current = temp;
		x--;
		setCount(x);
	}
	else{
		while(current != NULL){
			temp = current->next;
			if(social ==  (current->e).getSSN()){
				current->next = temp->next;
				delete temp;
				temp = current->next;
			}
			current = temp;
		}
		x--;
		setCount(x);
	}
}

//display the info of the employees, average salary, number of each role, and database size
void DB::displayEmployees() {
	current = head;
	double sal = 0;
	int count = 0;
	int cp = 0;
	int cm = 0;
	int cd = 0;
	cout << "FIRST NAME   LAST NAME Pay Type         SSN  DEPARTMENT        ROLE      SALARY/Pay Rate    " << endl;
	cout << endl;
	current = head;
 	while(current != NULL) {
        cout << setprecision(2) << fixed;
		if((current->e).getSalary() > 0){
			cout << setw(10) << (current->e).getFName(); 
			cout << setw(12) << (current->e).getLName();
			cout << setw(9) << "S";
			cout<< setw(12) << (current->e).getSSN() ;
			cout << setw(12) << (current->e).getDept();
			if ((current->e).getRole() == 1){
				cout << setw(12) << "programmer";
				cp++;
			}
			if ((current->e).getRole() == 2){
				cout << setw(12) << "manager";
				cm++;
			}
			if ((current->e).getRole() == 3){
				cout << setw(12) << "director";
				cd++;
			}
			cout  << setw(21) << (current->e).getSalary() << endl << endl;
			sal += (current->e).getSalary();
			count++;
			current = current->next;
		}
		else{
			cout << setw(10) << (current->e).getFName(); 
			cout << setw(12) << (current->e).getLName();
			cout << setw(9) << "H";
			cout<< setw(12) << (current->e).getSSN() ;
			cout << setw(12) << (current->e).getDept();
			if ((current->e).getRole() == 1){
				cout << setw(12) << "programmer";
				cp++;
			}
			if ((current->e).getRole() == 2){
				cout << setw(12) << "manager";
				cm++;
			}
			if ((current->e).getRole() == 3){
				cout << setw(12) << "director";
				cd++;
			}
			cout  << setw(18) << (current->e).getPayRate() << "/hr" << endl << endl;
			current = current->next;
		}
	}

	cout << endl;
	cout << "The average salary = " << (sal/count) << endl << endl;
	cout << "The number of programmers is " << cp << endl;
	cout << "The number of managers is " << cm << endl;
	cout << "The number of directors is " << cd << endl;
	sal = 0;
	count = 0;
	cout << "the size of the data base  is " << getSize() << endl << endl;
	displayEmployees((head->e).getRole());
}

// same as above but only for programmers
void DB::displayEmployees(const Role& p){
	current = head;
	double sal = 0;
	int count = 0;
	int cp = 0;
	cout << "FIRST NAME   LAST NAME PAY TYPE         SSN  DEPARTMENT        ROLE      SALARY/Pay Rate    " << endl;
	cout << endl;
	current = head;
    while(current != NULL) {
		if ((current->e).getRole() == 1){
            cout << setprecision(2) << fixed;
            cout << setw(10) << (current->e).getFName(); 
			cout << setw(12) << (current->e).getLName();
			if((current->e).getSalary() > 0){
				cout << setw(9) << "S";
			}
			else{
				cout << setw(9) << "H";
			}
			cout << setw(12) << (current->e).getSSN();
			cout << setw(12) << (current->e).getDept();
            if ((current->e).getRole() == 1){
				cout << setw(12) << "programmer";
				cp++;
            }
			if((current->e).getSalary() > 0){
				cout  << setw(21) << (current->e).getSalary() << endl << endl;
			}
			else{
				cout  << setw(18) << (current->e).getPayRate() << "/hr" << endl << endl;
			}
            if((current->e).getSalary() > 0){
				sal += (current->e).getSalary();
            count++;
			}
		}
        current = current->next;
	}
	if(sal > 0){ 
		cout << "The average salary of programmers = " << (sal/count) << endl << endl;
	}
	else{
		cout << "There are no salaried programmers" << endl << endl;
	}
}

// get the size of the database
int DB::getSize()const{
	return count;
}

//reassigns the salary of each employee
void DB::shuffleSalaries(double percent){
	current = head;
	double sal;
	double pay;
	while(current != NULL){
		if((current->e).getSalary() > 0){
			sal = (current->e).getSalary();
			sal = sal + (sal * percent);
			(current->e).setSalary(sal);
			if((current->e).getSalary() < 45000){
				(current->e).setSalary(45000);
			}
		}
		else{
			pay = (current->e).getPayRate();
			pay = pay + (pay * percent);
			(current->e).setPayRate(pay);			
		}
		temp = current->next;
		current = temp;
	}
}

//reassigns the role of each employee
void DB::setRoles(){
	current = head;
	Role x;
	while(current != NULL){
		if((current->e).getSalary() > 0){
			int i = rand() % 3 +1;
			if (i == 1){
				x = programmer;
				(current->e).setRole(x);
			}
			if ( i == 2){
				x = manager;
				(current->e).setRole(x);
			}
			if ( i == 3){
				x = director;
				(current->e).setRole(x);
			}
		}
		temp = current->next;
		current = temp;
	}
}

//changes the sizes 
void DB::setCount(int& s){
	count = s;
}
