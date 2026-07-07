class Solution {
public:
    int ROWS, COLS;
    void islandsAndTreasure(vector<vector<int>>& grid) 
    {//we do bfs instead of dfs as its more effective and we wont have to do repeated work.
     //because in dfs the first update will not be the least distance and hence we need to check again for that particular cell,
     //but in bfs the first update will be the closest one and hence we dont even have to check it again.
     //so in dfs we have to check if (distance < grid[r][c]) but in bfs if (grid[r][c] == INT_MAX) then we update and hence it wont be checked again
        ROWS = grid.size();
        COLS = grid[0].size();
        queue<pair<int,int>> q;
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                if (grid[i][j] == 0)
                    q.push({i,j});
            }
        }

        vector<pair<int,int>> directions (4);
        directions[0] = {-1,0};
        directions[1] = {1,0};
        directions[2] = {0,-1};
        directions[3] = {0,1};

        while(!q.empty())
        {
            pair<int,int> curr = q.front();
            q.pop();
            for (auto& dir : directions)
            {
                int r = curr.first + dir.first;
                int c = curr.second + dir.second;
                if (r < 0 || r >= ROWS || c < 0 || c >= COLS || grid[r][c] != INT_MAX)
                    continue;
                grid[r][c] = grid[curr.first][curr.second] + 1;
                q.push({r,c});
            }
        }
    }


};
