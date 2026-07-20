class Solution {
public:
    int maxProfit(vector<int>& prices) 
    { //we have 2 states on each day, either we are in buying state (dont own a stock) or selling state (own a stock)
        int size = prices.size();
        int dp1_buy = 0;
        int dp1_sell = 0;
        int dp2_buy = 0;
        for (int i = size - 1; i >=0; i--)
        {
            int dp_buy = max(dp1_sell - prices[i], dp1_buy); //the buying state value will be max of either if we bought (i.e we will be in selling state tomorrow and we subtract the current price from tomorrows selling state) or if we just dont do anything (i.e. we will be in buying state again tomorrow)
            int dp_sell = max(dp2_buy + prices[i], dp1_sell); //the selling state value will be max of either if we sold (i.e. we will be in buyign state on day after tomrrow due to cooldown and we add profit from day after tomorrows buying state) or if we hold (i.e. we will be in selling state again tomorrow)
            dp2_buy = dp1_buy;
            dp1_buy = dp_buy;
            dp1_sell = dp_sell;
        }
        return dp1_buy;
    }
};
