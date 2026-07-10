class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        unordered_map<int,vector<int>> premap;
        unordered_set<int> visitset;
        unordered_set<int> cycleset;
        vector<int> output;
        stack<int> st;
        for (int i = 0; i < numCourses; i++)
        {
            premap[i] = {};
        }
        for (auto& prereq : prerequisites)
        {
            premap[prereq[0]].push_back(prereq[1]);
        }
        for (int i = 0; i < numCourses; i++)
        {
            if (!dfs(i, premap, visitset, cycleset, st))
                return {};
        }
        while (!st.empty())
        {
            output.push_back(st.top());
            st.pop();
        }
        reverse(output.begin(), output.end());
        return output;
    }

private:
    bool dfs(int course, unordered_map<int,vector<int>>& premap, unordered_set<int>& visitset, unordered_set<int>& cycleset, stack<int>& st)
    {
        if (cycleset.count(course))
            return false;

        if (visitset.count(course))
            return true;
        
        cycleset.insert(course);

        for (int i : premap[course])
        {
            if(!dfs(i, premap, visitset, cycleset, st))
                return false;
        }
        st.push(course);
        cycleset.erase(course);
        visitset.insert(course);
        return true;
    }
};
