#ifndef NODE_H
#define NODE_H

#include "HourlyEmployee.h"
typedef Employee EMP;
struct Node {
		HourlyEmployee e;
		Node* next;
		
		Node();
		Node(HourlyEmployee);
		Node(HourlyEmployee, Node* next);
};

#endif

