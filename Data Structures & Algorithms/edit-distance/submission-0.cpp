class Solution {
public:
    int minDistance(string word1, string word2) 
    { //2d bottom up dp solution where at each position [i,j] we have the number of operations to make the strings equal till that word1[j] and word2[i]
      //to compute this if the letters match then the ans is just [i+1,j+1] but if it doesnt we have to do 1 + min (delete from word1 [i,j+1], insert into word1 [i+1,j] or replace[i+1,j+1])
      //we do bottom up as the values we need as each position will already be computed
      //to save space we have only 2 rows at a time where prevdp in the row above dp
        vector<int> dp(word1.length() + 1);
        for (int i = word2.length(); i >= 0; i--)
        {
            vector<int> prevdp(word1.length() + 1);
            if (i == word2.length())
            {
                int lastrow = 0;
                for (int j = word1.length(); j >=0; j--)
                {
                    prevdp[j] = lastrow;
                    lastrow++;
                }
            }
            else
            {
                for (int j = word1.length(); j >=0; j--)
                {
                    if (j == word1.length())
                    {
                        prevdp[j] = dp[j] + 1;
                        continue;
                    }
                    if (word1[j] == word2[i])
                        prevdp[j] = dp[j+1];
                    else
                    {
                        prevdp[j] = 1 + min(dp[j+1], min(dp[j], prevdp[j+1]));
                    }
                }
            }
            dp = prevdp;
        }
        return dp[0];
    }
};
