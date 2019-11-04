#include "linkedList.h"

LinkedList::LinkedList()
{
    head = new Node();
    length = 0;
}

LinkedList::~LinkedList()
{
    Node* p = head;
    Node* q = head;
    while(p)
    {
        q = p;
        p = p->next;

        delete q;
    }
}

bool
LinkedList::insert(int index, int data)
{
    // 带有头节点的链表
    Node* preNode = head;
    int i = 1;

    // 找到前一个节点
    while(preNode && i < index)
    {
        preNode = preNode->next;
        i++;
    }

    // i > index 防止index <= 0的情况出现
    if (!preNode || i > index)
    {
        return false;
    }

    Node* q = new Node();
    q->data = data;
    q->next = preNode->next;
    preNode->next = q;

    return true;
}

bool
LinkedList::remove(int index, int* data)
{
    Node* preNode = head;
    int i = 1;

    // 找到前一个节点
    while(preNode && preNode->next && i < index)
    {
        preNode = preNode->next;
        i++;
    }

    if (!preNode || !(preNode->next) || i > index)
    {
        return false;
    }

    Node* q = preNode->next;

    *data = q->data;

    preNode->next = q->next;

    delete q;
    q = nullptr;

    return true;
}

bool
LinkedList::getElem(int index, int* data)
{
    Node* curNode = head->next;
    int i = 1;

    while(curNode && i < index)
    {
        curNode = curNode->next;
        i++;
    }

    if (!curNode || i > index)
    {
        return false;
    }

    *data = curNode->data;

    return true;
}