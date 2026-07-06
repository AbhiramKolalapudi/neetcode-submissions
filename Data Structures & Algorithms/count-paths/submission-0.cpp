class Solution {
public:
    int uniquePaths(int m, int n) 
    {
        vector<int> row (n, 1);
        for (int i = m-2; i>=0; i--)
        {
            vector<int> newrow(n, 1);
            for (int j = n-2; j>=0; j--)
            {
                newrow[j] = newrow[j+1] + row[j];
            }
            row = newrow;
        }
        return row[0];
    }
};
