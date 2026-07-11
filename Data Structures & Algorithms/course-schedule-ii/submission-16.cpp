class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    { //basically we need to do reverse of a dfs topological sort 
      //we first have premap which is an adj list and then we have visitset which tells if we already visited a node
      //and a cycleset which tells us if we already visited a node in that path itself which means cycle detected and hence return false
      //and then we have a stack for the topological sort and we have temp array to reverse elements from stack and add it to output.
        unordered_map<int,vector<int>> premap;
        unordered_set<int> visitset;
        unordered_set<int> cycleset;
        vector<int> output;
        vector<int> temp;
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
            bool res = dfs(i, premap, visitset, cycleset, st);
            if (res == false)
                return {};
            else
            {
                while(!st.empty())
                {
                    temp.push_back(st.top());
                    st.pop();
                }
                reverse(temp.begin(), temp.end());
                for (int t : temp)
                    output.push_back(t);
                temp.clear();
            }
        }
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

        if (premap[course].empty())
            {
                st.push(course);
                cycleset.erase(course);
                visitset.insert(course);
                return true;
            }
        else
        {
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
    }
};