#ifndef DB_H
#define DB_H
#include "Node.h"
using namespace std;


class DB{
	private:
		Node* head;
		int count;
		Node* current;
		Node* temp;
		
	public:
		DB(int); 
		~DB(); 
		DB(const DB&);
		DB& operator=(const DB&);
		void insert(Employee&); 
		void insert(HourlyEmployee&);
		void remove(int); 
		void shuffleSalaries(double);  
		void setRoles();
		int getSize()const; 
		void displayEmployees(); 
		void displayEmployees(const Role&);
		void setCount(int&);
};

#endif
