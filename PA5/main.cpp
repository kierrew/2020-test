#include <iostream>
#include <string>
#include "HourlyEmployee.h"
#include "SalariedEmployee.h"
using namespace std;

int main(){
	srand(time(0));
	Employee* p[10];
	int const MaxS = 5;
	int const MaxH = 5;
	int Scount = 0;
	int Hcount = 0;
	int i = 0;
	while(Scount + Hcount != 10){
		int x = (rand() % 2);
		if(x == 0){
			if( Hcount == MaxH){
				continue;
			}
			else{
				p[i] = new HourlyEmployee;
				p[i]->setAllEmployee();
				Hcount++;
				i++;
			}
		}
		if(x == 1){
			if(Scount == MaxS){
				continue;
			}
			else{
				p[i] = new SalariedEmployee;
				p[i]->setAllEmployee();
				Scount++;
				i++;
			}
		}
	}
	
	cout << "FIRST NAME   LAST NAME Pay Type         SSN  DEPARTMENT        ROLE      SALARY/Pay Rate     BIWEEKLY SALARY" << endl;
	cout << endl;
	for(int i = 0; i < 10; i++){
		p[i]->print();
	}
	
	for(int i = 0; i < 10; i++){
		delete p[i];
	}
	return 0;
}