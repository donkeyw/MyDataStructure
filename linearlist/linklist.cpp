/*************************************************************************
	> File Name: linklist.cpp
	> Author: donkeywx
	> Mail: wangk9294@163.com
    > 带头结点的单链表
	> Created Time: Thu 10 Jan 2019 08:39:09 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node* next;
}Lnode, *LinkList;

bool initList(LinkList& head)
{

    head = new Lnode;
    if (NULL == head)
    {
        return false;
    }
    head->data = 12;
    head->next = NULL;
    
    return true;
}

void insertFromHead(LinkList& head, int data)
{

    Lnode* newNode = new Lnode;
    newNode->data = data;
    newNode->next = head->next;

    head->next = newNode;
}

void insertFromTail(LinkList& head, int data)
{
    
    Lnode* newNode = new Lnode;
    newNode->data = data;
    newNode->next = NULL;

    Lnode* tail = head;
    while(NULL != tail && NULL != tail->next) // 找到前一个
    {
        
        tail = tail->next;
    }

    tail->next = newNode;
}

bool insert(LinkList& head, int index, int data)
{
    
    Lnode* p = head;
    int j = 0;

    while(NULL != p && j < index-1) // 链表从下表为1开始
    {
        p = p->next;
        j ++;
    }

    if (NULL == p || j > index - 1)
    {

        return false;
    }

    Lnode* newNode = new Lnode;
    newNode->data = data;
    newNode->next = p->next;
    p->next = newNode;

    return true;
}

bool delet(LinkList& head, int index)
{
    
    Lnode* p = head;
    int j = 0;

    while(NULL != p->next && j < index - 1)
    {
        
        p = p->next;
        j ++;
    }

    if (NULL == p->next || j > index - 1)
    {
        
        return false;   //当i>n或i<1时，删除位置不合理
    }

    Lnode* q = p->next;
    p->next = p->next->next;
    delete q;
    q = NULL;

    return true;
}

void print(LinkList& head)
{

    Lnode* p = head->next;

    while(p)
    {
        
        cout << p->data << " ";
        p = p->next;
    }
    
    cout << endl;

}

int main(int argc, char** argv)
{

    LinkList head = NULL;
    initList(head);

    insertFromHead(head, 1);
    insertFromTail(head, 3);
    insert(head, 2, 2);
    insert(head, 1, 0);
    insert(head, 5, 4);
    print(head);

    delet(head, 1);
    delet(head, 2);
    delet(head, 3);
    print(head);
    
}
