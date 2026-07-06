class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int r = 1;
        int p = 0;
        while (l < (prices.size() - 1) && r < prices.size())
        {
            if (prices[l] > prices[r])
            {
                l = r;
                r++;
            }
            else
            {
                p = max(p, (prices[r] - prices[l]));
                r++;
            }
        }
        return p;
    }
};
