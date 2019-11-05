#include "doubleLinkedList.h"

DoubleLinkedList::DoubleLinkedList()
{
    head = new Node();
    head->pre = head->next = nullptr;
}

DoubleLinkedList::~DoubleLinkedList()
{
    Node* p = head;
    Node* q = nullptr;

    while(p)
    {
        q = p;
        p = p->next;

        // 前向指针应该设为空
        p->pre = nullptr;
        
        delete q;
        q = nullptr;
    }
}

bool
DoubleLinkedList::insert(int index, int data)
{
    Node* p = head;
    int i = 1;

    // 找到前驱
    while (p && i < index)
    {
        p = p->next;
        i++;
    }
    
    if (!p || i > index)
    {
        return false;
    }

    Node* s = new Node();
    s->data = data;

    s->pre = p;
    s->next = p->next;
    p->next->pre = s;
    p->next = s;
    
    return true;
}

bool
DoubleLinkedList::remove(int index, int* data)
{
    Node* p = head;
    int i = 1;

    // 找到前驱，也可以找到当前节点
    while(p && p->next && i < index)
    {
        p = p->next;
        i++;
    }

    if (!p || p->next || i > index)
    {
        return false;
    }

    Node* q = p->next;
    *data = q->data;

    p->next = q->next;
    q->next->pre = p;

    delete q;
    q = nullptr;

    return true;
}

bool
DoubleLinkedList::getElem(int index, int* data)
{
    Node* p = head->next;
    int i = 1;

    while(p && i < index)
    {
        p = p->next;
        i++;
    }

    if (!p || p->next || i > index)
    {
        return false;
    }

    *data = p->data;

    return true;
}