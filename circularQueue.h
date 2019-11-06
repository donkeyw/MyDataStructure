#ifndef __CIRCULAR_QUEUE_H__
#define __CIRCULAR_QUEUE_H__

#include "nonCopyable.h"

class CircularQueue: public NonCopyable
{
public:

    CircularQueue(int size);
    virtual ~CircularQueue();
    bool push(int data);
    bool pop();
    int top();
    bool empty();
    bool full();
    int getLegth();
private:
    int* elems;
    int maxSize;
    int topIndex;
    int rearIndex;
};

#endif