class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
        vector<vector<int>> res;
        priority_queue<pair<int, vector<int>>,vector<pair<int, vector<int>>>,greater<pair<int, vector<int>>>> minheap;
        //minheap that stores pair<distance,point>
        for (auto& point : points)
        {
            int distance = (point[0]*point[0]) + (point[1]*point[1]);
            minheap.push({distance, point});
        }
        for (int i = 0; i < k; i++)
        {
            res.push_back(minheap.top().second);
            minheap.pop();
        }
        return res;
    }
};
