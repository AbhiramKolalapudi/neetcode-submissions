class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int res = 0;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c]) {
                    res += 4;
                    if (r > 0 && grid[r - 1][c]) {
                        res -= 2;
                    }
                    if (c > 0 && grid[r][c - 1]) {
                        res -= 2;
                    }
                }
            }
        }
        return res;
    }
};