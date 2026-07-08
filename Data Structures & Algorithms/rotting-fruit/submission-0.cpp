class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int,int>> q;
        int time = 0;
        int fresh = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == 2)
                    q.push({i,j});
                if (grid[i][j] == 1)
                    fresh++;
            }
        }

        vector<pair<int,int>> directions (4);
        directions[0] = {-1,0};
        directions[1] = {1,0};
        directions[2] = {0,-1};
        directions[3] = {0,1};

        while(!q.empty() && fresh > 0)
        {
            int length = q.size();
            for (int i = 0; i < length; i++)
            {
                pair<int,int> curr = q.front();
                q.pop();
                for (auto& dir : directions)
                {
                    int r = curr.first + dir.first;
                    int c = curr.second + dir.second;
                    if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] != 1)
                        continue;
                    grid[r][c] = 2;
                    fresh--;
                    q.push({r,c});
                }
            }
            time++;
        }
        if (fresh == 0)
            return time;
        else
            return -1;
    }
};
