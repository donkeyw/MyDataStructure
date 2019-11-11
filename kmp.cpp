#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> getNext(string str)
{
    int length = str.length();
    vector<int> next(length + 1);
    next[0] = -1;

    int i = 0;
    int j = -1;

    while (i < length)
    {
        if (-1 == j || str[i] == str[j])
        {
            i ++;
            j ++;

            next[i] = j;
        }
        else
        {
            j = next[j];
        }
    }
    
    return next;
}

// str1 为需要匹配的字段
// str2 为正文
int kmp(string str1, string str2)
{
    int length1 = str1.length();
    int length2 = str2.length();
    vector<int> next = getNext(str1);

    int i = 0;
    int j = 0;

    while(i < length2)
    {
        if (0 == j || str1[i] == str2[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }

    if (length2 == j)
    {
        return j;
    }

    return -1;
}

int main()
{
    return 0;
}