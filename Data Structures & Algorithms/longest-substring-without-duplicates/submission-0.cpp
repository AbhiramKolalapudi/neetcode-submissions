class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxss = 0; //max size of substring
        int l = 0; //starting left index
        unordered_set <char> ss; //O(1) lookup using count
        for (int i = 0; i < s.length(); i++)
        {
            if(ss.count(s[i]) == 0) //add s[i] to set if doesnt exist
            {
                ss.insert(s[i]);
            }
            else //remove elements from beginning of subset until s[i] doesnt exits
            {
                while (ss.count(s[i]) != 0)
                {
                    ss.erase(s[l]);
                    l++;
                }
                ss.insert(s[i]);
            }
            maxss = max(maxss, (int)ss.size()); //max size of ss
        }
        return maxss;
    }
};
