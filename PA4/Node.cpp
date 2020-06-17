#include "Node.h"

//default constructor 
Node::Node(){
	next = NULL;
}

//constructor
Node::Node(HourlyEmployee e_param){
	e = e_param;
}
//constructor
Node::Node(HourlyEmployee e_param, Node* next){
	e = e_param;
	this-> next;
}
