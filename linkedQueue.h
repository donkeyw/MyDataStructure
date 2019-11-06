#ifndef __LINKED_QUEUE_H__
#define __LINKED_QUEUE_H__

#include "nonCopyable.h"

class Node
{
public:
    int data;
    Node* next;

    Node(){next = nullptr;}
    virtual ~Node(){}
};

class LinkedQueue: public NonCopyable
{
public:
    LinkedQueue();
    virtual ~LinkedQueue();

    bool push(int data);
    bool pop();
    int top();
private:
    Node* head;
    Node* rear;
};

#endif