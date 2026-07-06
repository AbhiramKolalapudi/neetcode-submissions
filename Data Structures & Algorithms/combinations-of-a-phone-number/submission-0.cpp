class Solution {
public:
    vector<string> letterCombinations(string digits) 
    {
        if (digits.empty())
            return {};
        vector<string> res;
        string curr;
        vector<string> keypad = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        backtrack(res, curr, keypad, digits, 0);
        return res;

    }

private:
    void backtrack(vector<string>& res, string& curr, vector<string>& keypad, string& digits, int i)
    {
        if (curr.length() == digits.length())
        {
            res.push_back(curr);
            return;
        }
        int num = digits[i] - '0';
        string chars = keypad[num];
        for (char c : chars)
        {
            curr.push_back(c);
            backtrack(res, curr, keypad, digits, i+1);
            curr.pop_back();
        }
    }
};
