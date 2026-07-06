class Solution {
int ROWS, COLS;
public:
    //the logic is that we start from the edges and mark its respective ocean's table as true
    //and then we see if its neighbours have height greater than or equal to it and then mark them also true 
    //because the water will flow to the egde only if the height is greater or equal
    //we recursively do this until all boxes are covered in the table for both the oceans
    //and then for any cords if both oceans tables are true then we add that cords to the res array
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        ROWS = heights.size();
        COLS = heights[0].size();
        vector<vector<int>> pacific(ROWS, vector<int>(COLS, 0)); //makes a 2d array of size ROWS, COLS and initialises all elements to 0
        vector<vector<int>> atlantic(ROWS, vector<int>(COLS, 0));

        for (int c = 0; c < COLS; c++) //to get first row and last row
        {
            dfs(heights, pacific, 0, c); //start dfs from first row for pacific
            dfs(heights, atlantic, ROWS - 1, c); //start dfs from last row for atlantic
        }

        for (int r = 0; r < ROWS; r++) //to get first and last column
        {
            dfs(heights, pacific, r, 0); //start dfs from first column for pacific
            dfs(heights, atlantic, r, COLS - 1); //start dfs from last column for atlantic
        }

        for (int r = 0; r < ROWS; r++)
        {
            for (int c = 0; c < COLS; c++)
            {
                if(pacific[r][c] && atlantic[r][c]) //if both pacific and atlantic are true then add {r,c} to result
                    res.push_back({r,c});
            }
        }

        return res;

    }

private:
    void dfs(vector<vector<int>>& heights, vector<vector<int>>& ocean, int r, int c)
    {
        ocean[r][c] = 1; //set current cords to 1 in ocean table

        //go to all neighbour cords of current i.e (r+1,c), (r-1,c), (r,c+1), (r,c-1)
        int nr = r + 1;
        int nc = c;
        if (nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS && !ocean[nr][nc] && heights[nr][nc] >= heights[r][c])//check if nr and nc are in range and then check if the height of nr,nc are greater than or equal to r,c and if yes then call dfs to nr,nc
            dfs(heights, ocean, nr, nc);

        nr = r - 1;
        nc = c;
        if (nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS && !ocean[nr][nc] && heights[nr][nc] >= heights[r][c])
            dfs(heights, ocean, nr, nc);
        
        nr = r;
        nc = c + 1;
        if (nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS && !ocean[nr][nc] && heights[nr][nc] >= heights[r][c])
            dfs(heights, ocean, nr, nc);
        
        nr = r;
        nc = c - 1;
        if (nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS && !ocean[nr][nc] && heights[nr][nc] >= heights[r][c])
            dfs(heights, ocean, nr, nc);

    }
};
