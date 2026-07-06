class Solution {
public:
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>> res;
        vector<string> curr;
        string defaultstr;
        vector<string> templates(n);
        for (int i = 0; i < n; i++)
        {
            defaultstr.push_back('.');
        }
        for(int i = 0; i < n; i++)
        {
            string newstr = defaultstr;
            newstr[i] = 'Q';
            templates[i] = newstr;
        }
        backtrack(n, res, curr, templates);
        return res;
    }

private:
    void backtrack(int n, vector<vector<string>>& res, vector<string>& curr, vector<string>& templates)
    {
        if (curr.size() == n)
        {
            res.push_back(curr);
            return;
        }
        
        for (int c = 0; c < n; c++)
        {
            if (safe(curr, c))
            {
                curr.push_back(templates[c]);
                backtrack(n, res, curr, templates);
                curr.pop_back();
            }
        }
    }

    bool safe(vector<string>& board, int pos)
    {
        int n = board.size();
        bool isSafe = true;
        if (n == 0)
            return true;
        
        int size = board[0].length();
        int leftdiag = pos - n;
        int rightdiag = pos + n;
        for (auto& prevpos : board)
        {
            if (leftdiag >= 0 && prevpos[leftdiag] == 'Q')
            {
                return false;
            }
            if (rightdiag < prevpos.size() && prevpos[rightdiag] == 'Q')
            {
                return false;
            }
            if (prevpos[pos] == 'Q')
                return false;
            leftdiag++;
            rightdiag--;
        }
        return true;
    }
};
