/*************************************************************************
	> File Name: kmp.cpp
	> Author:donkeywx 
	> Mail:wangkang 
	> Created Time: Tue 22 Jan 2019 08:36:55 PM CST
 ************************************************************************/

#include<iostream>
#include<string.h>
using namespace std;

int* getNext(string str)
{

    int* next = new int[str.size()];
    int i = 0;
    int j = -1;
    next[0] = -1;

    int len = str.size();
    while(i < len-1)
    {

        if (-1 == j || str[i] == str[j])
        {
            
            next[++i] = ++j;
        }
        else
        {
            
            j = next[j];
        }
    }

    return next;
}

void kmp(string str1, string str2)
{
    
    int* next = getNext(str2);
    int i = 0 ;
    int j = 0;

    int len1 = str1.size();
    int len2 = str2.size();
    while(i < len1 && j < len2)
    {

        if (-1 == j || str1[i] == str2[j])
        {
            
            ++ i;
            ++ j;
        }
        else
        {
            
            j = next[j];
        }
    }

    if (j == len2)
    {
        
        cout << i - j << endl;
    }
    else
    {
        
        cout << "false" << endl;
    }
}
int main(int argc, char ** argv)
{

    kmp("abacbcdhi", "bcd");

    return 0;
}

