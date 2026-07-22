class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) 
    { //2d bottom up dp where each row is a letter of s1 and each column is a letter of s2
      //we will have total of s1 + 1 rows and s2 + 1 columns 
      //and the last element of the 2d array will be true signifying that if the 2 pointers (i and j) reach that point then we successfully have interleaving string
      //so we start from that point and go backwards row-wise and every element will be true if s3[i + j] == s1[i] or s2[j] and if s1[j+1] or s2[i+1] == true
      //in the end if dp[0][0] is true we will return true
      //to save space we have only 2 rows at a time
        if (s1.size() + s2.size() != s3.size())
            return false;
        vector<bool> dp (s1.size() + 1, false);
        for (int i = s2.size(); i >= 0; i--)
        {
            vector<bool> newdp (s1.size() + 1, false);
            for (int j = s1.size(); j >= 0; j--)
            {
                if (i == s2.size() && j == s1.size())
                    newdp[j] = true;
                else if (j != s1.size() && s1[j] == s3[i + j] && newdp[j + 1])
                    newdp[j] = true;
                else if (i != s2.size() && s2[i] == s3[i + j] && dp[j])
                    newdp[j] = true;
            }
            dp = newdp;
        }
        return dp[0];
    }
};
