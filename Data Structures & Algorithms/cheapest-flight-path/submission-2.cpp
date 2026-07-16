class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {//bellman ford algo
        vector<int> prices(n, INT_MAX);
        prices[src] = 0;
        for (int i = 0; i <= k; i++)
        {
            vector<int> temp = prices;
            for (auto& flight : flights)
            {
                int price;
                if (prices[flight[0]] == INT_MAX)
                    price = INT_MAX;
                else
                    price = prices[flight[0]] + flight[2];
                if (price < temp[flight[1]])
                    temp[flight[1]] = price;
            }
            prices = temp;
        }
        if (prices[dst] == INT_MAX)
            return -1;
        return prices[dst];
    }
};
