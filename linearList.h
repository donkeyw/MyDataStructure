#ifndef __LINEAR_LIST_H__
#define __LINEAR_LIST_H__

#include "nonCopyable.h"

class LinearList: public NonCopyable
{
public:
    LinearList(int _maxSize);
    ~LinearList();

    bool insert(int index, int data);
    bool remove(int index, int* data);
    bool getElem(int index, int* data);
    int locateElem(int data);

    void print();
private:
    int maxSize;
    int* elements;
    int length; // 即为长度，也为指向下一个元素要插入的位置
};

#endif