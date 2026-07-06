class Solution {
public:
    string longestPalindrome(string s) 
    {//solution isnt 1DP ig 
     //we iterate through the string and take each element as center of a palindrome and check the highest length we can get 
     //by checking odd and even length palindrome and then update res if len is bigger
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
