class Solution {
public:
    int maxCoins(vector<int>& nums) 
    {//basically we iterate through nums and assume that we eliminate that element last so we compute the coint,
     //using the formula of that element * nums[l-1] * nums[r+1] + same for left sub array + same for right sub array
     //but we need to iterate through the array multiple times so instead we save the max results of subarray l,r at dp[l][r]
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
        return dfs (1, nums.size() - 2, dp, nums); 
    }

private:
    int dfs(int l, int r, vector<vector<int>>& dp, vector<int>& nums)
    {
        if (l > r)
            return 0;

        if (dp[l][r] != -1)
            return dp[l][r];

        for (int i = l; i < r + 1; i++)
        {
            int coins = nums[l-1] * nums[i] * nums[r+1];
            coins = coins + dfs(l, i-1, dp, nums) + dfs(i+1, r, dp, nums);
            dp[l][r] = max(dp[l][r], coins);
        }
        return dp[l][r];
    }
};
