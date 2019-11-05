#ifndef __CIRCULAR_LINKED_LIST_H__
#define __CIRCULAR_LINKED_LIST_H__

class Node
{
public:
    int data;
    Node* next;

    Node()
    {
        next = nullptr;
    }

    ~Node()
    {}
};

class CircularLinkedList
{
public:
    CircularLinkedList();
    ~CircularLinkedList();

    bool insert(int index, int data);
    bool remove(int index, int* data);
    bool getElem(int index, int* data);
private:
    Node* head;
};

#endif