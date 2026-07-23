class Solution {
public:
    int numDistinct(string s, string t) 
    {// basically we iterate thought both strings and if they dont match we go ahead only in t 
     // and if they match either we go ahead in both or go ahead only in s as we are trying to find how many ways t can fit in s
     // instead of recomputing this everytime we store that at dp  and the dfs fn will fill the dp and give us the final result
        vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
        return dfs(0, 0, s, t, dp);
    }

private:
    int dfs(int i, int j, string& s, string& t, vector<vector<int>>& dp) 
    {

        if (j == t.size()) 
            return 1;
        if (i == s.size()) 
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == t[j])
            dp[i][j] = dfs(i + 1, j + 1, s, t, dp) + dfs(i + 1, j, s, t, dp);
        else
            dp[i][j] = dfs(i + 1, j, s, t, dp);

        return dp[i][j];
    }
};