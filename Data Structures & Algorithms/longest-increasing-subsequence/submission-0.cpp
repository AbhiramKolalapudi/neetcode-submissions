class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> LIS(nums.size(), 1);
        LIS[nums.size() - 1] = 1;
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[j] > nums[i])
                {
                    if(LIS[j]+1 > LIS[i])
                        LIS[i] = LIS[j] + 1;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (LIS[i] > res)
                res = LIS[i];
        }
        return res;
    }
};
