class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {// basically we make a bool vector and first have the last value as true
     // and then iterate backwards in s using i and see if any word matches the string formed from i and if yes we have dp[i] = dp[i + word.size()]
     // so at last if dp[0] is true we return true
        vector<bool> dp(s.size() + 1);
        dp[s.size()] = true;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            for (auto& word : wordDict)
            {
                if (i + word.size() <= s.size() && s.substr(i,word.size()) == word)
                    dp[i] = dp[i + word.size()];
                if (dp[i])
                    break;
            }
        }
        return dp[0];
    }
};
