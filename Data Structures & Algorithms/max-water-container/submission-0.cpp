class Solution {
public:
    int maxArea(vector<int>& heights) 
    {
        int l = 0; //we start with the widest container
        int r = heights.size() - 1;
        int hmax = 0;
        while (l < r)
        {
            int h = (r-l) * (min(heights[l],heights[r])); //area
            if (h > hmax)
                hmax = h;
            if (heights[l] < heights[r]) //we move the lower height 
            {
                l++;
                continue;
            }
            else // if both are equal then it doesnt matter
            {
                r--;
                continue;
            }
        }
        return hmax;
    }
};
