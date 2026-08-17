class NumMatrix {
private:
    vector<vector<int>> summat;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        summat = vector<vector<int>>(rows + 1, vector<int>(cols + 1, 0));
        int prefixsum = 0;

        for (int i = 1; i <= rows; i++)
        {
            int rowsum = 0;
            for (int j = 1; j <= cols; j++)
            {
                int above = summat[i - 1][j];
                rowsum += matrix[i-1][j-1];
                summat[i][j] = above + rowsum;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = summat[row2+1][col2+1] - summat[row1][col2 + 1] - summat[row2 + 1][col1] + summat[row1][col1];
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */