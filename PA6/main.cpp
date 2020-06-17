#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "HourlyEmployee.h"
#include "SalariedEmployee.h"
#include <cstdlib>
using namespace std;

void usage(){
	cout << "usage: PA6 data file" << endl;
}

Employee* parseData(string line){
	string firstName;
	string lastName;
	string SSN;
	string department;
	string salary;
	string payRate;
	string role;
	string hours;
	Role roll;
	Employee* p;
	int count = 0;
	//read each line
	stringstream x(line);
	while(x >>firstName >> lastName >> SSN >> department >> salary >> payRate >> role >> hours){
	}
	// determine wether to make an hourly or salaried employee
	double sal = atof(salary.c_str());
	if(sal == -1){
		int pay = atof(payRate.c_str());
		int hrs = atoi(hours.c_str());
		int rol = atoi(role.c_str());
		if (rol == 1){
			roll = programmer;
		}
		if ( rol == 2){
			roll = manager;
		}
		if ( rol == 3){
			roll =  director;
		}
		try{
			p = new HourlyEmployee();
		}
		catch(bad_alloc & ba){
			cerr << "bad_alloc caught: " << ba.what();
		}
		// fill hourly employee member fields
			p->setFirstName(firstName);
		p->setLastName(lastName);
		p->setSSN(SSN);
		p->setDept(department);
		p->setSalary(sal);
		p->setRole(roll);
		p->setPayRate(pay);
		p->setHoursWorked(hrs);
	}
	else{
		int rol = atoi(role.c_str());
		if (rol == 1){
			roll = programmer;
		}
		if ( rol == 2){
			roll = manager;
		}
		if ( rol == 3){
			roll =  director;
		}
		try{
			p = new SalariedEmployee();
		}
		catch(bad_alloc & ba){
			cerr << "bad_alloc caught: " << ba.what();
		}
		// fill salaried member fields 
		p->setFirstName(firstName);
		p->setLastName(lastName);
		p->setSSN(SSN);
		p->setDept(department);
		p->setSalary(sal);
		p->setRole(roll);
		p->setBiweeklySalary();
	}
	return p;
}


int main(int argc, char* argv[]){
	
	if(argc < 2){
		usage();
		exit(1);
	}
	// opening data file 
	fstream fin;
	fin.open(argv[1], ios::in);
	if(fin.fail()){
		cout << "File not open" << endl;
		exit(1);
	}
	
	// creating an array of e,p;oyee pointers
	Employee* p[10];
	int i = 0;
	cout << "FIRST NAME   LAST NAME Pay Type         SSN  DEPARTMENT        ROLE      SALARY/Pay Rate     BIWEEKLY SALARY" << endl;
	
	//reading each line of the data file 
	string input;
	while(getline(fin, input)){
		p[i] = parseData(input);
		// display the info of each employee
		p[i]->print();
		i++;
	}
	
	//display the number of each error
	cout <<"The # of bad_alloc errors is " << Employee::errA << endl;
	cout <<"The # of name errors is " << Employee::errB << endl;
	cout <<"The # of SSN errors is " << Employee::errC << endl;
	cout <<"The # of department errors is " << Employee::errD << endl;
	cout <<"The # of salary errors is " << Employee::errE << endl;
	cout <<"The # of pay rate errors is " << Employee::errF << endl;
	cout <<"The # of hours worked errors is " << Employee::errG << endl;

	// closing the data file 
	fin.close();
	
	//memory management
	for(int i = 0; i < 10; i++){
		delete p[i];
	}
	
	return 0;
}