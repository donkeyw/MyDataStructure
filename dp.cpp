#include <iostream>
#include <vector>

using namespace std;

int coins(int money)
{
    vector<int> dp(money + 1, money + 1);
    int coins[3] = {1, 2, 5};
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 1; i <= money; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i - coins[i] < 0)
            {
                continue;
            }

            dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
        }
    }
    return dp[money];
}


// leetcode 516
int longestPalindromeSubseq(string s) {
    int size = s.size();
    vector<vector<int>> dp(size, vector<int>(size, 0)); // 从i到j的最长

    // dp[i][j] = max(dp[i+1][j], dp[i][j-1])
    //           如果s[j] == s[i]相等 dp[i-1][j-1] + 2

    for (int i = size - 1; i >= 0; i--)
    {
        dp[i][i] = 1;
        for (int j = i+1; j < size; j++)
        {
            if (s[j] == s[i])
            {
                dp[i][j] = dp[i+1][j-1] + 2;
            }
            else
            {
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
            
        }
    }

    return dp[0][size-1];

}

// 300 
int lengthOfLIS(vector<int>& nums) {

    vector<int>dp (nums.size(), 1);
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int res = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        res = max(res, dp[i]);
    }

    return res;
}

int main()
{
    cout << coins(11) << endl;
}