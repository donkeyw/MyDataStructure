#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

void dfs(string str, string& temp, vector<string>& result, vector<bool>& visited, int len)
{
    if (str.length() == len)
    {
        result.push_back(temp);
        return;
    }

    for (int i = 0; i < str.length(); i++)
    {
        if (true == visited[i])
        {
            continue;
        }

        temp.push_back(str[i]);
        visited[i] = true;
        dfs(str, temp, result, visited, len + 1);
        temp.pop_back();
        visited[i] = false;
    }
}

void permDfs(string str, vector<string>& result)
{
    vector<bool> visited(str.length(), false);
    string temp = "";
    dfs(str, temp, result, visited, 0);
}

bool isSwap(string& str, int from, int to)
{
    for (int i = from; i < to; i++)
    {
        if (str[i] == str[to])
        {
            return false;
        }
    }

    return true;
}

void helper(string& str, vector<string>& result, int from, int to)
{
    if (from == to)
    {
        result.push_back(str);
        return;
    }

    for (int i = from; i <= to; i++)
    {
        if (isSwap(str, from, i))
        {
            swap(str[from], str[i]);
            helper(str, result, from + 1, to);
            swap(str[i], str[from]);
        }
    }
}

void perm(string str, vector<string>& result)
{
    helper(str, result, 0, str.length() - 1);
}

void helper_1(string& str, string& temp, vector<string>& result, int index, int len)
{
    if (str.length() - index + temp.length() < len)
    {
        return;
    }

    if (temp.length() == len)
    {
        result.push_back(temp);
        return ;
    }    

    temp.push_back(str[index]); // 添加当前字符串
    helper_1(str, temp, result, index + 1, len);

    temp.pop_back();    // 不添加字符串
    helper_1(str, temp, result, index + 1, len);
}

/////// combination
void comb(string str, vector<string>& result)
{
    for (int i = 1; i <= str.length(); i++)
    {
        string temp = "";
        helper_1(str, temp, result, 0, i);
    }
}

void comb_01(string str, vector<string>& result)
{
    uint32_t len = str.length();
    uint32_t nums = (1 << len) - 1; // 组合的个数

    for (uint32_t i = 1; i <= nums; i++)
    {
        string temp = "";
        uint32_t tmp = i;
        uint32_t index = 0;

        while (tmp)
        {
            if (tmp & 0x01) // 逐个查看哪一位是1
            {
                temp.push_back(str[index]);
            }
            tmp = tmp >> 1;
            index ++;
        }
        
        result.push_back(temp);
    }
}

int main(int argc, char** argv)
{

    vector<string> result;
    string str = "abc";

    comb_01(str, result);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }
    return 0;
}