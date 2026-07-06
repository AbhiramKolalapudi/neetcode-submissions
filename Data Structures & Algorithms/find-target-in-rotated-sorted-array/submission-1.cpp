class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int l = 0;
        int r = (nums.size() - 1);
        while (l <= r)
        {
            int m = (l + r)/2;
            if (target == nums[m])
                return m;
            if (nums[m] >= nums[l]) //we are in left set
            {
                if (target > nums[m] || target < nums[l]) //target is more than mid or in right set
                    l = m + 1;
                else //target is left of mid and in left set
                    r = m - 1;
            }
            else //we are in right set
            {
                if (target < nums[m] || target > nums[r]) //target is less than mid or in left set
                    r = m - 1;
                else //target is right of mid and in right set
                    l = m + 1;
            }
        }
        return -1;
    }
};
