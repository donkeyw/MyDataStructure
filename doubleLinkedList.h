#ifndef __DOUBLE_LINKED_LIST_H__
#define __DOUBLE_LINKED_LIST_H__

#include "nonCopyable.h"

class Node
{
public:
    int data;
    Node* pre;
    Node* next;

    Node()
    {
        pre = next = nullptr;
    }

    ~Node()
    {}
};

class DoubleLinkedList: public NonCopyable
{
public:
    DoubleLinkedList();
    virtual ~DoubleLinkedList();

    bool insert(int index, int data);
    bool remove(int index, int* data);
    bool getElem(int index, int* data);
private:
    Node* head;
};

#endif