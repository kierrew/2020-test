a.out: Main.o Node.o Employee.o DB.o HourlyEmployee.o
	g++ Main.o Node.o Employee.o DB.o HourlyEmployee.o -o a.out
	
Main.o: Employee.h HourlyEmployee.h Main.cpp
	g++ -c -g Main.cpp
	
Employee.o: Employee.h Employee.cpp
	g++ -c -g Employee.cpp
	
HourlyEmployee.o: Employee.h HourlyEmployee.h HourlyEmployee.cpp
	g++ -c -g HourlyEmployee.cpp

DB.o: Employee.h HourlyEmployee.h DB.cpp
	g++ -c -g DB.cpp

Node.o: Employee.h HourlyEmployee.h Node.cpp
	g++ -c -g Node.cpp
			
clean:
	rm *.o a.out