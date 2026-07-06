class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int cursum = 0;
        int maxsum = nums[0];
        for (int n:nums)
        {
            if (cursum < 0)
                cursum = 0;
            cursum += n;
            if (cursum > maxsum)
                maxsum = cursum;
        }
        return maxsum;
    }
};
