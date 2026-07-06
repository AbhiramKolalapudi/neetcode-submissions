class Solution {
public:
    int numDecodings(string s) 
    {// we start from right and we have 3 variables dp, dp1 and dp2 and we just shift left and dp will be 0 if str[i] = 0 else it will be dp1 or dp1 + dp2 depending if i is < 3 and i+1 is < 7 (10-26)
        int dp = 0;
        int dp1 = 1;
        int dp2 = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if(s[i] == '0')
                dp = 0;
            else 
            {
                dp = dp1;
                if (i + 1 < s.size() && (s[i] == '1' || s[i] == '2' && s[i + 1] < '7'))
                    dp = dp1 + dp2;
            }
            dp2 = dp1;
            dp1 = dp;
            dp = 0;
        }
        return dp1;
    }
};
