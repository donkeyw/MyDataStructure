#include <iostream>
#include <string>
#include <vector>
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

// 动态规划
int longestPalindrome_2(string str)
{
    int len = str.length();
    if (len < 2)
    {
        return 0;
    }

    int dp [len][len] = {0};
    int maxlen = 0;
    int start = 0;
    for (int i = 0; i < len; i++)
    {
        dp[i][i] = 1;
        for (int j = 0; j < i; j++)
        {
            // i -j < 2是满足长度
            // if (i - j < 2) {
            //         // 子字符串长度小于 2 的时候单独处理
            //         lps[j][i] = chars[i] == chars[j];
            //     } else {
            //         // 如果 [i, j] 是回文子串，那么一定有 [j+1, i-1] 也是回子串
            //         lps[j][i] = lps[j + 1][i - 1] && (chars[i] == chars[j]);
            //     }
            dp[j][i] = (str[i] == str[j]) && (i - j < 2 || dp[j+1][i-1]);
            int temp = i - j + 1;
            if (dp[j][i] && temp > maxlen)
            {
                maxlen = temp;
                start =  j;
            }
        }
    }

    cout << start << endl;
    return maxlen;
}

// 马拉车算法
int longestPalindrome_3(string str)
{
    int len = str.length();
    string newStr = "$#";

    for (int i = 0; i < len; i++)
    {
        newStr += str[i];
        newStr += "#";
    }
    int newLen = newStr.length();

    int p[newLen] = {0};
    int id = 0;
    int max = 0;
    int mid = 0;
    int res = 0;

    for (int i = 1; i < newLen; i++)
    {  
        // 在范围内
        if (i < max)
        {
            p[i] = min(p[2 * id - i], max - i);
        }
        // 不再范围内
        else
        {
            p[i] = 1;
        }
        
        while ((i - p[i] > 0) 
            && (i + p[i] < newLen) 
            && newStr[i-p[i]] == newStr[i+p[i]])
        {
            p[i] ++;
        }

        // 更新max边界和中心点id
        if (i + p[i] > max)
        {
            max = i + p[i];
            id = i;
        }

        if (p[i] > res)
        {
            res = p[i];
        }
    }

    // 起始点
    cout << (id - res) / 2 << endl;

    return res - 1;
    // https://www.cnblogs.com/grandyang/p/4475985.html
}

// Longest Palindromic Subsequence

int lpsHelper(string str, int left, int right)
{
    if(left == right)
    {
        return 1;
    }
    else if (left > right)
    {
        return 0;
    }

    // 首位相同
    if (str[left] == str[right])
    {
        // 注意递归方法
        return lpsHelper(str, left + 1, right - 1) + 2;
    }
    // 首位不同
    else
    {
        return max(lpsHelper(str, left + 1, right), lpsHelper(str, left, right - 1));
    }
}

int lps_1(string str)
{
    return lpsHelper(str, 0, str.length() - 1);
}

int lps_2(string str)
{
    int len = str.length();
    int dp[len][len] = {0};

    for (int i = 0; i < len; i ++)
    {
        dp[i][i] = 1;
    }
    for (int i = 1; i < len; i++)
    {
        for (int j = 0; j + i < len ; j++)
        {
            if (str[j] == str[j + i])
            {
                dp[j][j + i] = dp[j + 1][j + i - 1] + 2;
            }
            else
            {
                dp[j][j + i] = max(dp[j + 1][j + i], dp[j][j + i - 1]);
            }
            
        }
    }

    return dp[0][len-1];
}


int lps_3(string str){
    int n=str.length();
    vector<vector<int> > dp(n,vector<int>(n));
 
    for(int j=0;j<n;j++){
        dp[j][j]=1;
// 计算dp[i][j]时需要计算dp[i+1][*]或dp[*][j-1]，因此i应该从大到小，即递减；j应该从小到大，即递增
        for(int i=j-1;i>=0;i--){
            if(str[i]==str[j])
                dp[i][j]=dp[i+1][j-1]+2;
            else
                dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
        }
    }
    return dp[0][n-1];
}

int main(void)
{
    // cout << longestPalindrome_1("aababa") << endl;
    // cout << longestPalindrome_2("aababa") << endl;
    // cout << longestPalindrome_3("aababa") << endl;

    // lps
    cout << lps_1("cabbeafc") << endl;
    cout << lps_2("cabbeafc") << endl;
    cout << lps_3("cabbeafc") << endl;
    
    return 0;
}