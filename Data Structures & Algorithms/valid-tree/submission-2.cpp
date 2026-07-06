class Solution {
public:
// a graph is a tree if its connected and has no cycles
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjlist(n);
        for (auto& edge : edges) //make adjacency list which is a 2d vector in which if edge 0 to 1 exists then adjlist[0] = [1] and adjlist[1] = [0]
        {
            adjlist[edge[0]].push_back(edge[1]);
            adjlist[edge[1]].push_back(edge[0]);
        }
        unordered_set<int> visited; //keeps track of visited nodes for cycle detection and checking connectivity
        if (!dfs(0, -1, adjlist, visited)) //if dfs fails then return false
            return false;
        
        return visited.size() == n; //if the graph is connected (all elements visited by starting dfs at 0) then return true else return false
    }

private:
    bool dfs(int node, int parent, vector<vector<int>>& adjlist, unordered_set<int>& visited)
    {
        if(visited.count(node))//visiting an already visited node (that is not parent) hence return false
            return false;

        visited.insert(node);
        for (int nei : adjlist[node])
        {
            if (nei == parent)//dont call dfs on parent as we will go back in path and parent will be in visited already
                continue;
            if (!dfs(nei, node, adjlist, visited)) //call dfs for all neighbours and if any fails then return false
                return false;
        }
        return true;
    }
};

