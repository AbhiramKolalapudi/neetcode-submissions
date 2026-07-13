class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) 
    {//we do dfs from JFK and visit all edges and if we go to some deadend we backtrack
        unordered_map<string, vector<string>> adjlist;
        vector<string> res;
        res.push_back("JFK");
        int edges = tickets.size() + 1;
        sort(tickets.begin(), tickets.end());
        for (auto& t : tickets)
        {
            adjlist[t[0]].push_back(t[1]);
        }
        string start = "JFK";
        dfs(start, res, adjlist, edges);
        return res;

    }

private:
    bool dfs(string& src, vector<string>& res, unordered_map<string, vector<string>>& adjlist, int edges)
    {
        if (res.size() == edges)
            return true;
        
        if (adjlist[src].empty())
            return false;
        
        for (int i = 0; i < adjlist[src].size(); i++)
        {
            string next = adjlist[src][i];
            res.push_back(next);
            adjlist[src].erase(adjlist[src].begin() + i);
            
            if (dfs(next, res, adjlist, edges))
                return true;
            
            adjlist[src].insert(adjlist[src].begin() + i, next); //while backtracking we insert in the original position so that the lexicographic order doesnt mess up
            res.pop_back();
        }
        return false;
    }
};
