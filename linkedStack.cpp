#include "linkedStack.h"

LinkedStack::LinkedStack()
{
    head = new Node();
}

LinkedStack::~LinkedStack()
{
    Node* p = head;
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
LinkedStack::push(int data)
{
    Node* p = new Node();
    p->data = data;
    p->next = head->next;

    head->next = p;

    return true;
}

bool
LinkedStack::pop()
{
    if (empty())
    {
        return false;
    }

    Node* p = head->next;
    head->next = p->next;

    delete p;
    p = nullptr;

    return true;
}

bool
LinkedStack::empty()
{
    return (nullptr == head->next);
}

// 需要优化
int
LinkedStack::top()
{
    if (empty())
    {
        return false;
    }

    return (head->next->data);
}
