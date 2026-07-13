class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {//dijikstras algorithm (we made our own adj list from times)
        priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> minHeap;
        vector<int> time(n+1, INT_MAX);
        vector<vector<pair<int,int>>> adj(n+1);
        time[0] = 0;
        time[k] = 0;
        minHeap.push({0,k});
        for (auto& t : times)
            adj[t[0]].push_back({t[1], t[2]});
        
        while(!minHeap.empty())
        {
            int source = minHeap.top().second;
            int currtime = minHeap.top().first;
            minHeap.pop();
            if (currtime > time[source])
                continue;
            for (auto [nei, weight] : adj[source])
            {
                if (weight + currtime < time[nei])
                {
                    time[nei] = currtime + weight;
                    minHeap.push({currtime + weight, nei});
                }
            }
        }
        auto res = *max_element(time.begin(), time.end());
        if (res == INT_MAX)
            return -1;
        return res;
    }
};
