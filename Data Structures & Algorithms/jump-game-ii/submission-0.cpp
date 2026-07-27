class Solution {
public:
    int jump(vector<int>& nums) 
    {//move l and r pointers for each jump and use that (l,r) window to generate next (l,r) while increase res everytime
        int l = 0;
        int r = 0;
        int res = 0;
        while (r < nums.size() - 1)
        {
            int farthest = 0;
            for (int i = l; i <= r; i++)
            {
                farthest = max(farthest, i + nums[i]);
            }
            l = r + 1;
            r = farthest;
            res++;
        }
        return res;
    }
};
