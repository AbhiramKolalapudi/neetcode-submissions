class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) 
    {//dijikstras algo
        int n = grid.size();
        vector<vector<bool>> visit(n, vector<bool>(n, false));
        priority_queue<pair<int, pair<int,int>>,vector<pair<int, pair<int,int>>>,greater<pair<int, pair<int,int>>>> minheap;
        minheap.push({grid[0][0],{0,0}});
        while(!minheap.empty())
        {
            int sourcex = minheap.top().second.first;
            int sourcey = minheap.top().second.second;
            int time = minheap.top().first;
            minheap.pop();
            if (visit[sourcex][sourcey])
                continue;
            if (sourcex == n - 1 && sourcey == n - 1)
                return time;
            visit[sourcex][sourcey] = true;
            
            vector<pair<int,int>> directions{{0,1}, {1,0}, {0,-1}, {-1,0}};

            for (auto& d : directions)
            {
                int newx = sourcex + d.first;
                int newy = sourcey + d.second;
                if (newx >= n || newy >= n || newx < 0 || newy < 0 || visit[newx][newy])
                    continue;
                
                int newtime = max(time, grid[newx][newy]);
                minheap.push({newtime,{newx,newy}});
            }
            
        }
        return -1;
    }
};
