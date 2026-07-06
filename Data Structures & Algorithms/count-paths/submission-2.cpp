class Solution {
public:
    int uniquePaths(int m, int n) 
    {// basically we make a table[m][n] that stores how many ways are there to reach bottom right and we start with bottom right value to be 1
     // and then from there we compute each value as table[x][y] = table[x+1][y] + table[x][y+1], which is basically its right and down value
     // and the bottom most row and right most column will always be 1
     // but for space optimisation we take one row at a time as row from bottom and will be all 1's at first 
     // and then we make a newrow in which newrow[j] = newrow[j+1] + row[j] and then do row = newrow and then go up one level
     // and in the end we return row[0]
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
