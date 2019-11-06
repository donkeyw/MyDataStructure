#include "circularQueue.h"

CircularQueue::CircularQueue(int size)
    : maxSize(size), topIndex(0), rearIndex(0)
{
    elems = new int[maxSize];
}

CircularQueue::~CircularQueue()
{
    if (nullptr != elems)
    {
        delete elems;
        elems = nullptr;
    }
}

bool
CircularQueue::full()
{
    return ( (rearIndex + 1) % maxSize == topIndex );
}

bool
CircularQueue::empty()
{
    return (topIndex == rearIndex);
}

bool
CircularQueue::push(int data)
{
    if (full())
    {
        return false;
    }

    elems[rearIndex] = data;
    rearIndex = (rearIndex + 1) % maxSize;

    return;
}

bool
CircularQueue::pop()
{
    if (empty())
    {
        return false;
    }

    topIndex = (topIndex + 1) % maxSize;
}

int
CircularQueue::top()
{
    if (empty())
    {
        return false;
    }

    return elems[topIndex];
}

int
CircularQueue::getLegth()
{
    return (rearIndex - topIndex + maxSize) % maxSize;
}