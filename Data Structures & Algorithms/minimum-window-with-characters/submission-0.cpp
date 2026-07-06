class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map <char, int> countT;
        unordered_map <char, int> window;
        int l = 0;
        int have = 0;
        int res[2] = {0,0};
        int reslen = INT_MAX;
        for (char& c : t)
        {
            countT[c]++;
        }
        int need = countT.size();
        for (int i=0; i < s.length(); i++)
        {
            window[s[i]]++;
            if (window[s[i]] == countT[s[i]])
                have++;
            while (have == need)
            {
                if ((i-l+1) < reslen)
                {
                    reslen = i-l+1;
                    res[0] = l;
                    res[1] = i;
                }
                window[s[l]]--;
                if (window[s[l]] < countT[s[l]])
                    have--;
                l++;
            }
        }
        if (reslen == INT_MAX)
            return "";
        string res_string = s.substr(res[0], (res[1]-res[0]+1));
        return res_string;
    }
};
