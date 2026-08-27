class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int ROWS = matrix.size(), COLS = matrix[0].size();
        vector<vector<int>> res(COLS, vector<int>(ROWS));

        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                res[c][r] = matrix[r][c];
            }
        }

        return res;
    }
};