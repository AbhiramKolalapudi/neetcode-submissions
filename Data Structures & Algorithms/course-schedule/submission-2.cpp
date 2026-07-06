class Solution {
public:
    //the logic is that we have a graph from x -> y and to finish x we need to finish y,
    //so if x doesnt point to anything that means it can be finished and has no requirements.
    //we will have a premap which maps course x to all the courses that you must take to finish x
    //visitset has all courses we visited in current dfs path so that we can detect cycles
    unordered_map<int,vector<int>> premap;
    unordered_set<int> visitset;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (int i = 0; i < numCourses; i++)//initialise premap
        {
            premap[i] = {};
        }
        for (auto& prereq : prerequisites)//add courses to premap
        {
            premap[prereq[0]].push_back(prereq[1]);
        }

        for (int i = 0; i < numCourses; i++)//do dfs to all elements (we can do for only 0 but the graph may not be connected)
        {
            if (!dfs(i))
                return false;
        }
        return true;//if dfs doesnt return false then return true
    }

private:
    bool dfs(int course)
    {
        if (visitset.count(course))//if its already in visitset then cycle exists hence retrun false
            return false;

        if (premap[course].empty())//if its empty then nothing is required to do that course hence return true
            return true;

        visitset.insert(course);
        for (int pre : premap[course])
        {
            if (!dfs(pre))
                return false;
        }
        visitset.erase(course);//backtrack and remove that element from visitset
        //if all element's dfs has returned true then clear its mapped vector
        return true;//no cycles found

    }
};
