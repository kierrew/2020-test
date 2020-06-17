a.out: main.o Employee.o HourlyEmployee.o SalariedEmployee.o
	g++ main.o Employee.o HourlyEmployee.o SalariedEmployee.o -o a.out
	
main.o: Employee.h HourlyEmployee.o SalariedEmployee.o main.cpp
	g++ -c -g main.cpp
	
Employee.o: Employee.h Employee.cpp
	g++ -c -g Employee.cpp
	
HourlyEmployee.o: Employee.h HourlyEmployee.h HourlyEmployee.cpp
	g++ -c -g HourlyEmployee.cpp
	
SalariedEmployee.o: Employee.h SalariedEmployee.h SalariedEmployee.cpp
	g++ -c -g SalariedEmployee.cpp