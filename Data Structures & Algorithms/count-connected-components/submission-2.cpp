class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjlist(n);
        for (auto& edge : edges)
        {
            adjlist[edge[0]].push_back(edge[1]);
            adjlist[edge[1]].push_back(edge[0]);
        }
        vector<int> visited(n, 0);
        int components = 0;
            for (int i = 0; i < n; i++)
            {
                if (!visited[i])
                {
                    dfs(i, adjlist, visited);
                    components++;
                }
            }
        return components;
    }

private:
    void dfs(int node, vector<vector<int>>& adjlist, vector<int>& visited)
    {
        visited[node] = 1;
        for (int nei : adjlist[node])
        {
            if(!visited[nei])
                dfs(nei, adjlist, visited);
        }
    }
};
