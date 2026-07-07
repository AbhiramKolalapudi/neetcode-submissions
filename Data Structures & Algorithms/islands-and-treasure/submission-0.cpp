class Solution {
public:
    int ROWS, COLS;
    void islandsAndTreasure(vector<vector<int>>& grid) 
    {
        ROWS = grid.size();
        COLS = grid[0].size();
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                if (grid[i][j] == 0)
                    dfs(grid, i, j, 0);
            }
        }    
    }

private:
    void dfs(vector<vector<int>>& grid, int r, int c, int distance)
    {
        if (r < 0 || r >= ROWS || c < 0 || c >= COLS || grid[r][c] == -1 || distance > grid[r][c])
            return;
        
        grid[r][c] = distance;
        distance++;
        dfs(grid, r - 1, c, distance);
        dfs(grid, r + 1, c, distance);
        dfs(grid, r, c - 1, distance);
        dfs(grid, r, c + 1, distance);

    }
};
