class Solution {
public:
    unordered_map<int,vector<int>> premap;
    unordered_set<int> visitset;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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
            if (!dfs(i))
                return false;
        }
        return true;
    }

private:
    bool dfs(int course)
    {
        if (visitset.count(course))
            return false;

        if (premap[course].empty())
            return true;

        visitset.insert(course);
        for (int pre : premap[course])
        {
            if (!dfs(pre))
                return false;
        }
        visitset.erase(course);
        premap[course].clear();
        return true;

    }
};
