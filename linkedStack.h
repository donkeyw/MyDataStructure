#ifndef __LINKED_STACK_H__
#define __LINKED_STACK_H__

#include "nonCopyable.h"

class Node
{
public:
    int data;
    Node* next;

    Node(){next = nullptr;}
    virtual ~Node(){}
};

class LinkedStack: public NonCopyable
{
public:
    LinkedStack();
    virtual ~LinkedStack();

    bool push(int data);
    bool pop();
    int top();
    bool empty();
private:
    Node* head;
};

#endif