class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for (const auto& s : strs)
        {
            int i = s.length();
            res = res + to_string(i) + "#" + s;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i{0};
        while (i < s.length())
        {
            int len{0};
            while (s[i] != '#')
            {
                len = len*10 + (s[i] - '0');
                i++;
            }
            i++;
            string temp = "";
            for (int j{0}; j < len; j++)
            {
                temp = temp + s[i+j];
            }
            res.push_back(temp);
            i = i + len;
        }
        return res;
    }
};
