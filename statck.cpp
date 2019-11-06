#include "stack.h"

Stack::Stack(int size)
    : maxSize(size), topIndex(-1)
{
    elems = new int[maxSize];
}

Stack::~Stack()
{
    if (nullptr != elems)
    {
        delete[] elems;
        elems = nullptr;
    }
}

bool 
Stack::push(int data)
{
    if (full())
    {
        return false;
    }

    elems[++topIndex] = data;

    return true;
}

bool
Stack::pop()
{
    // 栈为空
    if (empty())
    {
        return false;
    }

    topIndex --;

    return true;
}

int 
Stack::top()
{
    if (-1 == topIndex)
    {
        return false;
    }

    return elems[topIndex];
}

bool
Stack::empty()
{
    return (-1 == topIndex);
}

bool
Stack::full()
{
    return (maxSize - 1 == topIndex);
}