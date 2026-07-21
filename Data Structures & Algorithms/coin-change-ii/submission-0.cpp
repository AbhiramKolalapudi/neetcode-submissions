class Solution {
public:
    int change(int amount, vector<int>& coins) 
    { //so basically we do bottom up dp where rows are the coins and columns are amount and an element dp[x][y] means the total combinations to get amount y using only coins >= x index in coins vector
      //we start from first coloumn of bottom most row and we do the sum of the (i) bottom element (i.e. combination to get that amount with coins > x index) and (ii) the left element (i.e. if we take the coin then see remaining amount in that row itself)
      //if the coin is bigger than amount then (ii) will be 0 
      //the space optimal version will only store 2 rows at a time
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        for (int i = coins.size()-1; i >= 0; i--)
        {
            vector<int> nextdp(amount+1, 0);
            nextdp[0] = 1;
            for (int j = 1; j <= amount; j++)
            {
                if (j - coins[i] < 0)
                    nextdp[j] = dp[j];
                else
                    nextdp[j] = dp[j] + nextdp[j-coins[i]];
            }
            dp = nextdp;
        }
        return dp[amount];
    }
};
