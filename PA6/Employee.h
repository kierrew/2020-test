#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <ctime>

using namespace std;

enum Role {programmer = 1, manager = 2, director = 3};

class Employee {
	protected:
		string firstName;
		string lastName;
		string SSN;
		string department;
		double salary;
		Role   role;
		static const string dpt[5];
		string* payStub;
		int     cntPS;
		static int cntEMP;
		void   displayPayStub() const;
		

	public:

		static int errA;
		static int errB;
		static int errC;
		static int errD;
		static int errE;
		static int errF;
		static int errG;
		Employee();
		Employee(string, string, int, string, double, Role);
		Employee(const Employee&);
		//~Employee();

		string getFName() const;
		string getLName() const;
		void setFirstName(string);
		void setLastName(string);

		string    getSSN() const;
		void   setSSN(string);

		string getDept() const;
		void   setDept(string);

		double getSalary() const;
		virtual void   setSalary(double);

		Role   getRole() const ;
		void   setRole(Role);

		void   directDeposit(string);

		Role setRolesM(int);
		/*void setSalaryM();
		void setSSNM();
		void setFName();
		void setLName();
		void setDepartmentM();
		virtual void setAllEmployee();*/
		virtual void print () = 0;
		virtual double getPayRate();
		virtual void setPayRate(double);
		virtual void setHoursWorked(int);
		virtual void setBiweeklySalary();
		int getcount();
		
		class InvalidSSN{};
		
};
#endif