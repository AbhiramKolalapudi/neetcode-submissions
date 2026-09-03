class Solution {
public:
    int integerBreak(int n) 
    {
        vector<int> dp (n+1);
        for (int i = 0; i < n; i++)
        {
            dp[i] = i;
        }
        dp[n] = 0;

        for (int num = 2; num <= n; num++)
        {
            for (int i = 1; i < num; i++)
            {
                int val = dp[i] * dp[num - i];
                dp[num] = max(dp[num], val);
            }
        }
        return dp[n];
    }
};