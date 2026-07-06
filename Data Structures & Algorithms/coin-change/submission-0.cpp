class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    { // basically we have an array dp where dp[i] = min no. of coins to get amount i
        vector<int> dp(amount + 1, amount + 1); // we initialise an array of size amount+1 and all values to amount+1 as computed values will always be lesser than that
        dp[0] = 0; //we start with dp[0] = 0
        for (int i = 1; i <= amount; i++) //iterate i from 1 to amount to set each dp[i]
        {
            for (int j = 0; j < coins.size(); j++) //check each coin in the coins array
            {
                if (i - coins[j] >= 0) //if the coin is smaller than or equal to i
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1); //then set dp[i] to min of already available dp[i] and 1 + dp[i- coinvalue]
            }
        }
        return dp[amount] > amount ? -1 : dp[amount]; //at last return dp[amount] if we got a value else dp[amount] will be amount + 1 then return -1
    }
};
