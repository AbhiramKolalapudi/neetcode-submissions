class Solution {
public:
    string longestPalindrome(string s) 
    {//solution isnt 1DP ig 
     //we
        string res = "";
        int resLen = 0;
        for (int i = 0; i < s.length(); i++)
        {
            //checking odd length case
            int l = i;
            int r = i;
            while (l >= 0 && r < s.length() && s[l] == s[r]) 
            {
                if ((r - l + 1) > resLen) 
                {
                    res = s.substr(l, r - l + 1);
                    resLen = r - l + 1;
                }
                l--;
                r++;
            }

            //checking even length case
            l = i;
            r = i+1;
            while (l >= 0 && r < s.length() && s[l] == s[r]) 
            {
                if ((r - l + 1) > resLen) 
                {
                    res = s.substr(l, r - l + 1);
                    resLen = r - l + 1;
                }
                l--;
                r++;
            }
        }
        return res;
    }
};
