#include "linkedQueue.h"

LinkedQueue::LinkedQueue()
{
    head = new Node();
    rear = head;
}

LinkedQueue::~LinkedQueue()
{
    Node* p = new Node();
    Node* q = nullptr;

    while (p)
    {
        q = p;
        p = p->next;

        delete q;
        q = nullptr;
    }
}

bool
LinkedQueue::push(int data)
{
    Node* p = new Node();
    p->data = data;

    rear->next = p;
    rear = p;

    return true;
}

bool
LinkedQueue::pop()
{
    if (nullptr == head->next)
    {
        return false;
    }

    Node* p = head->next;
    head->next = p->next;

    delete p;
    p = nullptr;
}

int
LinkedQueue::top()
{
    if (nullptr == head->next)
    {
        return false;
    }

    return head->next->data;
}