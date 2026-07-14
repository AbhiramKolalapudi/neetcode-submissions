class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) 
    {//prims algo
        int res = 0;
        unordered_set<int> visit;
        priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> minheap;
        minheap.push({0,0});
        while(visit.size() != points.size())
        {
            int point = minheap.top().second;
            int cost = minheap.top().first;
            minheap.pop();
            if (visit.count(point))
                continue;
            visit.insert(point);
            res = res + cost;
            for (int i = 0; i < points.size(); i++)
            {
                if (visit.count(i))
                    continue;
                if (i == point)
                    continue;

                int xdist = abs(points[point][0] - points[i][0]);
                int ydist = abs(points[point][1] - points[i][1]);
                minheap.push({xdist+ydist, i});
            }
        }
        return res;
    }
};
