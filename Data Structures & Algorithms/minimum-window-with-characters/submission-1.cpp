class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map <char, int> countT;
        unordered_map <char, int> window;
        int l = 0;
        int have = 0;//have is no. of unique chars in substr
        int res[2] = {0,0};//startig and ending index of res
        int reslen = INT_MAX;
        for (char& c : t)
        {
            countT[c]++;
        }
        int need = countT.size();//need is no. of unique chars in t
        //need is total no of conditions we need and have is total no of conditions we met
        for (int i=0; i < s.length(); i++)
        {
            window[s[i]]++;
            if (window[s[i]] == countT[s[i]])
                have++; //if one of the condition is met increase have
            while (have == need) //all conditions met
            {
                if ((i-l+1) < reslen)//new res better than prev
                {
                    reslen = i-l+1;
                    res[0] = l;
                    res[1] = i;
                }
                window[s[l]]--;//decrease window size until all conditions not met
                if (window[s[l]] < countT[s[l]])
                    have--;
                l++;
            }
        }
        if (reslen == INT_MAX)//no substr found
            return "";
        string res_string = s.substr(res[0], (res[1]-res[0]+1)); //make substr using res
        return res_string;
    }
};
