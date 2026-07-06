class Solution {
public:
    int trap(vector<int>& height) {
    //so the formula to find how much water can be stored at each position is (min(maxl, maxr) - height[i]) (only +ve)
    //so instead of storing maxl and maxr in an array or computing everytime, we take 2 pointers and just move the min pointer 
    //and update the max of that side and then calculate how much water can be at that position and update res.
        int l = 0; 
        int r = height.size() - 1;
        int maxl = 0;
        int maxr = 0;
        int water = 0;
        int res = 0;
        while (l < r)
        {
            if (height[l] < height[r])
            {
                maxl = max(maxl, height[l]);
                l++;
                water = maxl - height[l];
                if (water >= 0)
                    res = res + water;
            }
            else 
            {
                maxr = max(maxr, height[r]);
                r--;
                water = maxr - height[r];
                if (water >= 0)
                    res = res + water;
            }
        }
        return res;
    }
};
