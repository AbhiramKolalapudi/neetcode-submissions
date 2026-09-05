class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<int> below(cols + 1, INT_MAX);
        below[cols-1] = 0;

        for (int i = rows - 1; i >= 0; i--)
        {
            vector<int> dp(cols + 1, 0);
            
            dp[cols] = INT_MAX;

            for (int j = cols - 1; j >= 0 ; j--)
            {
                dp[j] = grid[i][j] + min(below[j], dp[j+1]);
            }
            below = dp;
        }

        return below[0];
    }
};