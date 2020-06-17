#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

using namespace std;

enum Role {programmer = 1, manager = 2, director = 3};

class Employee {
	private:
		string first;
		string last;
		int    SSN;
		string department;
		double salary;
		Role   role;
    /*
		string* payStub;
		int     count;
		void   displayPayStub() const;
*/
	public:

		Employee();
		Employee(string, string, int, string, double, Role);
		Employee(const Employee&);
		//~Employee();
		Employee& operator=(const Employee&);

		string getFName() const;
		string getLName() const;
		void setFirstName(string);
		void setLastName(string);

		int    getSSN() const;
		void   setSSN(int);

		string getDept() const;
		void   setDept(string);

		double getSalary() const;
		void   setSalary(double);

		Role   getRole() const ;
		void   setRole(Role);

		void   directDeposit(string);

		void setSalaryM(Employee*&);
		void setRolesM(Employee*&);
		void setSSNM(Employee*&);
		void setFName(Employee*&);
		void setLName(Employee*&);
		void setDepartmentM(Employee*&);
		void setAllEmployee(Employee*&);
};
#endif