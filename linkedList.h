#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include "nonCopyable.h"

class Node
{
public:
    Node()
    {
        next = nullptr;
    }
    ~Node()
    {
        if (nullptr != next)
        {
            delete next;
            next = nullptr;
        }
    }
public:
    int data;
    Node* next;

};

class LinkedList: public NonCopyable
{
public:

    LinkedList();
    ~LinkedList();

    bool insert(int index, int data);
    bool remove(int index, int* data);
    bool getElem(int index, int* data);

private:

    Node* head;    
    int length;
};

#endif