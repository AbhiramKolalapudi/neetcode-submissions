class Solution {
public:
    int ROWS, COLS;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxarea = 0;
        ROWS = grid.size();
        COLS = grid[0].size();
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                if (grid[i][j] == 1) //if there exists an island in the grid
                {
                    int area = 0;
                    dfs(grid, i, j, area); //run dfs on it
                    if (area > maxarea)
                        maxarea = area;
                }
            }
        }
        return maxarea;
    }

private:
    void dfs (vector<vector<int>>& grid, int r, int c, int& area)
    {//similar to previous question, but we maintain area in dfs fn and we have an interger maxarea instead of islands for finding biggest area
     //we increase area everytime the neightbour is not 0 and then again visit all neighbours and check
        if (r < 0 || r >= ROWS || c < 0 || c >= COLS || grid[r][c] == 0)
            return;
        
        area++;
        grid[r][c] = 0;

        dfs(grid, r - 1, c, area);
        dfs(grid, r + 1, c, area);
        dfs(grid, r, c - 1, area);
        dfs(grid, r, c + 1, area);

    }
};
