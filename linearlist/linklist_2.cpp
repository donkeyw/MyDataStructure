/*************************************************************************
	> File Name: linklist.cpp
	> Author:donkeywx 
	> Mail:wangkang 
    > 不带头结点的单链表
	> Created Time: Thu 10 Jan 2019 09:51:12 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class Node
{
public:
    Node(){}
    Node(int data, Node* &next)
    {

        this->data = data;
        this->next = next;
    }

    int data;
    Node* next;
};

class LinkList
{
public:

    LinkList(){}

    Node* findNth(int index)
    {
        Node* p = head;
        int j = 1;
        while(NULL != p && j < index)
        {
            
            p = p->next;
            j ++;
        }
        if (j == index)
        { 
            return p;
        }
        else
        {
            return NULL;
        }
    }


    bool insertFront(int data)
    {
        Node* newNode = new Node(data, head);

        head = newNode;
    }

    bool insertEnd(int data)
    {
        
    }

    bool insert(int data, int index)
    {
        Node* newNode = NULL;
       if (1 == index)
       {

           newNode = new Node(data, head);
           head = newNode;
           return true;
       }
    
        Node* p = findNth(index - 1);
        if (NULL == p)
        {
            
            return false;
        }

        newNode = new Node(data, p->next);
        p->next = newNode;

        return true;
    }

    bool del(int index)
    {
        
        if (NULL == head)
        {

            return false;
        }

        Node* p = NULL;
        if(1 == index)
        {
            
            p = head;
            head = head->next;
            delete p;
            p = NULL;
        }

        Node* q = findNth(index - 1);
        if (NULL == q || NULL == q->next)
        {
            return false;
        }

        p = q->next;
        q->next = p->next;
        delete p;
        p = NULL;
    
        return true;
    }

    void print()
    {
        
        Node* p = head;

        while(NULL != p)
        {

            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }

private:
    Node* head = NULL;
};

int main(int argc, char** argv)
{

    LinkList *list = new LinkList();
    list->insert(1, 1);
    list->insert(2, 2);
    list->insert(0, 1);

    list->del(0);
    list->del(4);
    list->print();

}

