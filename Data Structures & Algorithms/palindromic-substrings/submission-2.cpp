class Solution {
public:
    int countSubstrings(string s)  
    {//almost same as prev qn, but we just have res that stores number of palindromes
        int res = 0;
        int resLen = 0;
        for (int i = 0; i < s.length(); i++)
        {
            //checking odd length case
            int l = i;
            int r = i;
            while (l >= 0 && r < s.length() && s[l] == s[r]) 
            {
                res++;
                l--;
                r++;
            }

            //checking even length case
            l = i;
            r = i+1;
            while (l >= 0 && r < s.length() && s[l] == s[r]) 
            {
                res++;
                l--;
                r++;
            }
        }
        return res;
    }
};
