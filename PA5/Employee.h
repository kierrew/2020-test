#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <ctime>

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

		void setSalaryM();
		void setRolesM();
		void setSSNM();
		void setFName();
		void setLName();
		void setDepartmentM();
		virtual void setAllEmployee();
		virtual void print () = 0;
		virtual double getPayRate();
		
};
#endif