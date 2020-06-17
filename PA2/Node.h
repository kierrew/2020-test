#ifndef NODE_H
#define NODE_H

#include "Employee.h"
typedef Employee EMP;
struct Node {
    EMP e;
    Node* next;

    Node();
    Node(EMP);
    Node(EMP, Node* next);
};

Node::Node()
{
    next = NULL;
}

Node::Node(EMP e_param)
{
    e = e_param;
}

Node::Node(EMP e_param, Node* next)
{
    e = e_param;
    this->next =  next;
}

#endif

