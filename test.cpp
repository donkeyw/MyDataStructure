#include "linearList.h"
#include <unordered_map>
int main()
{
    std::unordered_map<int, int > map;
    LinearList list(5);
    list.insert(0, 1);
    list.insert(1, 1);
    list.insert(2, 2);
    list.insert(3, 3);
    list.insert(5, 3);
    list.print();

    int* data = new int;
    list.remove(0, data);
    list.remove(3, data);

    list.getElem(1, data);

    list.print();
    return 0;
}