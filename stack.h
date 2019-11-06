#ifndef __STACK_H__
#define __STACK_H__

#include "nonCopyable.h"

class Stack: public NonCopyable
{
public:
    Stack(int size);
    virtual ~Stack();

    bool push(int data);
    bool pop();
    int top();
    bool empty();
    bool full();

private:
    int* elems;
    int topIndex;    // 指向栈的顶端
    int maxSize;
};

// 如果是两个堆栈需要共享空间，则可以设置两个下标，一个指向头，一个指向尾，头尾游标相差1的时候则为满栈

#endif