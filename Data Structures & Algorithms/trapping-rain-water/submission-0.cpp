class Solution {
public:
    int trap(vector<int>& height) 
    {
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
