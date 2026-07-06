class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    { //basically we take outer elements of the matrix and rotate them and then go to the inner elements and then rotate them until we are left with none
        int l = 0;
        int r = matrix.size() - 1;
        while (l < r)
        {
            for (int i=0; i < r - l; i++)
            {
                int top = l;
                int bottom = r;
                int temp = matrix[top][l + i]; //save top left
                matrix[top][l + i] = matrix[bottom - i][l]; //move bl to tl
                matrix[bottom - i][l] = matrix[bottom][r - i]; //move br to bl
                matrix[bottom][r - i] = matrix[top + i][r]; //move tr to br
                matrix[top + i][r] = temp; //move saved tl to tr
            }
            l++;
            r--;
        }
    }
};
