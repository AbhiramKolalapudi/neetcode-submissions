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
                if (grid[i][j] == '1') //if there exists an island in the grid
                {
                    dfs(grid, i, j); //run dfs on it
                    islands++; //and increment islands
                }
            }
        }
        return islands;
    }

private:
    void dfs (vector<vector<char>>& grid, int r, int c)
    {
        //in this func we just change the grid to 0 and visit all its neighbours which are islands too and mark them 0 too
        //we mark the neighbours 0 so that if [1 1] exists, its counted as a single island
        //so in the above func when we run dfs it marks that element and all its neighbours and their neighbours etc as 0 and then increments island so that we dont repeat
        if (r < 0 || r >= ROWS || c < 0 || c >= COLS || grid[r][c] == '0')
            return;

        grid[r][c] = '0';

        dfs(grid, r - 1, c);
        dfs(grid, r + 1, c);
        dfs(grid, r, c - 1);
        dfs(grid, r, c + 1);

    }
};
