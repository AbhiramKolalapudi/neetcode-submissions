class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> curr;
        backtrack(s, 0, res, curr);
        return res;
    }

private:
    void backtrack(string s, int i, vector<vector<string>>& res, vector<string>& curr)
    {
        if(i >= s.length())
        {
            res.push_back(curr);
            return;
        }

        for (int j = i; j < s.length(); j++)
        {
            if (isPali(s, i, j)) 
            {
                curr.push_back(s.substr(i, j - i + 1));
                backtrack(s, j+1, res, curr);
                curr.pop_back();
            }
        }
    }

    bool isPali(const string& s, int l, int r) 
    {
        while (l < r) 
        {
            if (s[l] != s[r])
                return false;

            l++;
            r--;
        }
        return true;
    }
};
