class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjlist(n);
        for (auto& edge : edges)
        {
            adjlist[edge[0]].push_back(edge[1]);
            adjlist[edge[1]].push_back(edge[0]);
        }
        unordered_set<int> visited;
        int components = 0;
            for (int i = 0; i < n; i++)
            {
                if (!visited.count(i))
                {
                    dfs(i, adjlist, visited);
                    components++;
                }
            }
        return components;
    }

private:
    void dfs(int node, vector<vector<int>>& adjlist, unordered_set<int>& visited)
    {
        visited.insert(node);
        for (int nei : adjlist[node])
        {
            if(!visited.count(nei))
                dfs(nei, adjlist, visited);
        }
    }
};
