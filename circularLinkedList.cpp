#include "circularLinkedList.h"

CircularLinkedList::CircularLinkedList()
{
    head = new Node();
    head->next = head;
}

CircularLinkedList::~CircularLinkedList()
{
    Node* p = head->next;
    Node* q;
    while (p != head)
    {
        q = p;
        p = p->next;
        
        delete q;
        q = nullptr;
    }

    delete head;
    head = nullptr;
}

// 插入，删除，查找操作和单链表一致
bool
CircularLinkedList::insert(int index, int data)
{

}