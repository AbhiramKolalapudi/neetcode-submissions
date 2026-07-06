class Solution {
public:
    vector<string> generateParenthesis(int n) 
    {
        vector<int> available (2, n);
        vector<string> res;
        string temp = "";
        backtrack(available, res, temp);
        return res;
    }

private:
    void backtrack(vector<int>& available, vector<string>& res, string& temp)
    {
        if (available[0] == 0 && available[1] == 0)
        {
            res.push_back(temp);
            return;
        }
        if (available[0] > 0)
        {
            temp.push_back('(');
            available[0]--;
            backtrack(available, res, temp);
            temp.pop_back();
            available[0]++;
        }
        if (available[1] > available[0])
        {
            temp.push_back(')');
            available[1]--;
            backtrack(available, res, temp);
            temp.pop_back();
            available[1]++;
        }
    }
};
