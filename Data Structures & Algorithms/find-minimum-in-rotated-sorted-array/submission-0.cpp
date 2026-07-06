class Solution {
public:
    int findMin(vector<int> &nums) 
    {
        int l = 0;
        int r = (nums.size() - 1);
        int res = nums[0];
        while (l <= r)
        {
            if(nums[l] < nums[r])
            {
                res = min(res, nums[l]);
                break;
            }
            int m = (l + r)/2;
            res = min(res, nums[m]);
            if (nums[m] >= nums[l])
                l = m + 1;
            else 
                r = m - 1;
        }
        return res;
    }
};
//the logic is that a rotated array will have 2 sorted sets
//and the minimum element will always be the first element in right set
//(unless it is rotated n times, then minimum element will be nums[0])
//so we find middle m and if m is in left set then we go l = m + 1 as we first element in right set
//and if m is in right set then we go r = m - 1 as we need first element in right set
//we check if m is in left set or right set by doing, if nums[m] >= nums[l] then its left set
