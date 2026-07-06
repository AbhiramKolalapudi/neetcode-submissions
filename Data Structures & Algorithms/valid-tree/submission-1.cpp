class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjlist(n);
        for (auto& edge : edges)
        {
            adjlist[edge[0]].push_back(edge[1]);
            adjlist[edge[1]].push_back(edge[0]);
        }
        unordered_set<int> visited;
        if (!dfs(0, -1, adjlist, visited))
            return false;
        
        return visited.size() == n;
    }

private:
    bool dfs(int node, int parent, vector<vector<int>>& adjlist, unordered_set<int>& visited)
    {
        if(visited.count(node))
            return false;

        visited.insert(node);
        for (int nei : adjlist[node])
        {
            if (nei == parent)
                continue;
            if (!dfs(nei, node, adjlist, visited))
                return false;
        }
        return true;
    }
};

