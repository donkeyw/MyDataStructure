#include <iostream>
#include <string>

using namespace std;

// 中心扩散方法，时间复杂度为O^2
void helper_1(string str, int left, int right, int& maxlen, int& start)
{
    while(left >= 0  && right < str.length() && str[left] == str[right])
    {
        left --;
        right ++;
    }

    // 需要注意计算长度的公式
    int len = right - left - 1;
    if (len > maxlen)
    {
        maxlen = len;
        start = left + 1;
    }
}
int longestPalindrome_1(string str)
{
    int len = str.length();
    if (len < 2)
    {
        return 0;
    }

    int maxlen = 0;
    int start = 0;

    for (int i = 0; i < len; i++)
    {
        // 区分奇数和偶数
        helper_1(str, i, i, maxlen, start);
        helper_1(str, i, i + 1, maxlen, start);
    }
    cout << start << endl;
    return maxlen;
}



int main(void)
{
    cout << longestPalindrome_1("aababa") << endl;
    return 0;
}