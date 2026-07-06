class Solution {
public:
    int ROWS, COLS;
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        ROWS = grid.size();
        COLS = grid[0].size();
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                if (grid[i][j] == '1')
                {
                    dfs(grid, i, j);
                    islands++;
                }
            }
        }
        return islands;
    }

private:
    void dfs (vector<vector<char>>& grid, int r, int c)
    {
        if (r < 0 || r >= ROWS || c < 0 || c >= COLS || grid[r][c] == '0')
            return;

        grid[r][c] = '0';

        dfs(grid, r - 1, c);
        dfs(grid, r + 1, c);
        dfs(grid, r, c - 1);
        dfs(grid, r, c + 1);

    }
};
