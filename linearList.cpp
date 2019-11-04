#include "linearList.h"
#include <iostream>

LinearList::LinearList(int _maxSize)
    : maxSize(_maxSize), length(0)
{
    elements = new int[maxSize];
}

LinearList::~LinearList()
{
    if (nullptr != elements)
    {
        delete[] elements;
        elements = nullptr;
    }
}

// 将数据插入到指定下标
bool 
LinearList::insert(int index, int data)
{
    // 已满
    if (maxSize == length)
    {
        return false;
    }

    // 插入位置 - 实际数组下标 = 1
    int insertLocation = index - 1;
    // 插入位置错误
    if (insertLocation < 0 || insertLocation > length)
    {
        return false;
    }

    // 插入元素
    // 如果需要插入最后一个元素，则不用整体后移
    if (length > insertLocation)
    {
        for(int i = length; i > insertLocation; i--)
        {
            elements[i] = elements[i - 1];
        }
    }
    elements[insertLocation] = data;
    length ++;

    return true;
}

bool 
LinearList::remove(int index, int* data)
{
    int delLocation = index - 1;
    if (delLocation < 0 || delLocation >= length)
    {
        return false;
    }

    *data = elements[delLocation];

    // 删除元素
    if (delLocation < length - 1)   // 这句话可以不需要
    {
        for (int i = delLocation; i < length; i++)
        {
            elements[i] = elements[i + 1];
        }
    }

    length --;

    return true;
}

bool
LinearList::getElem(int index, int* data)
{
    int location = index - 1;
    if (location < 0 || location >= length)
    {
        return false;
    }

    *data = elements[location];

    return true;
}

int
LinearList::locateElem(int data)
{
    if (nullptr == elements)
    {
        return -1;
    }

    for (int i = 0; i < length; i++)
    {
        if (data == elements[i])
        {
            return i;
        }
    }

    return -1;
}

void
LinearList::print()
{
    if (nullptr == elements)
    {
        return -1;
    }
    for (int i = 0; i < length; i++)
    {
        std::cout << elements[i] << " ";
    }

    std::endl;
}