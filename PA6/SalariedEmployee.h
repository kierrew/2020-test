#ifndef SALARIEDEMPLOYEE_H
#define SALARIEDEMPLOYEE_H

#include <string>
#include "Employee.h"

using namespace std;


class SalariedEmployee : public Employee{
private:
	double biweeklySalary;
	
public:
	SalariedEmployee();
    SalariedEmployee(string, string, int, string, double, Role);
    ~SalariedEmployee();
	
	void setBiweeklySalary();
	double getBiweeklySalary() const;
	//void setAllEmployee();
	virtual void print ();
	void setSalary(double);
};
#endif
