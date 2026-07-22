class Solution {
public:
int rows;
int cols;
    int longestIncreasingPath(vector<vector<int>>& matrix) 
    { //find LIP for each element but if the neighbours already computed it, do 1+neighbours' length
        rows = matrix.size();
        cols = matrix[0].size();
        int res = 0;
        vector<vector<int>> LIP (rows, vector<int>(cols, 0));
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (LIP[i][j] == 0)
                    dfs(i, j, matrix, LIP, res);
            }
        }
        return res;
    }

private:
    void dfs(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& LIP, int& res)
    {
        int longest = 1;
        if (j != 0 && matrix[i][j-1] > matrix[i][j]) //left
        {
            if (LIP[i][j-1] == 0)
                dfs(i, j-1, matrix, LIP, res);
            longest = max(longest, LIP[i][j-1] + 1);
        }
        if (i != 0 && matrix[i-1][j] > matrix[i][j]) //up
        {
            if (LIP[i-1][j] == 0)
                dfs(i-1, j, matrix, LIP, res);
            longest = max(longest, LIP[i-1][j] + 1);
        }
        if (i != rows-1 && matrix[i+1][j] > matrix[i][j]) //down
        {
            if (LIP[i+1][j] == 0)
                dfs(i+1, j, matrix, LIP, res);
            longest = max(longest, LIP[i+1][j] + 1);
        }
        if (j != cols-1 && matrix[i][j+1] > matrix[i][j]) //right
        {
            if (LIP[i][j+1] == 0)
                dfs(i, j+1, matrix, LIP, res);
            longest = max(longest, LIP[i][j+1] + 1);
        }
        LIP[i][j] = longest;
        res = max(res, longest);
    }
};
