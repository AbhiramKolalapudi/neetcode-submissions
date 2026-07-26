class Solution {
public:
    bool isMatch(string s, string p) 
    { //we do normal regex solution itself but then add caching as one check might be done multiple times
        vector<vector<int>> cache(s.size() + 1, vector<int>(p.size() + 1, -1)); //dp using caching
        return dfs(0, 0, s, p, cache);
    }

private:
    bool dfs(int i, int j, string& s, string& p, vector<vector<int>>& cache)
    {
        if (j == p.size()) //if we are out of p then we should be out of s also (other way around doesnt work as * can be there in p while s is empty)
            return i == s.size();

        if (cache[i][j] != -1)
            return cache[i][j];
        
        bool matched = (i < s.size()) && ((s[i] == p[j]) || (p[j] == '.'));

        if (j+1 < p.size() && p[j+1] == '*')
        {
            cache[i][j] = (dfs(i, j+2,s, p, cache)) || (matched && dfs(i+1, j, s, p, cache));
            return cache[i][j];
        }

        if (matched)
        {
            cache[i][j] = dfs(i+1, j+1, s, p, cache);
            return cache[i][j];
        }
        
        cache[i][j] = false;
        return false;
    }
};
