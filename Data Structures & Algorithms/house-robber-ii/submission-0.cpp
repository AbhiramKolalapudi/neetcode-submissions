class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1)
            return(nums[0]);
        vector<int> nums1(nums.begin() + 1, nums.end());
        vector<int> nums2(nums.begin(), nums.end() - 1);
        return(max(helper(nums1), helper(nums2)));
    }
    
private:
    int helper(vector<int>& nums)
    {
        int r1 = 0;
        int r2 = 0;
        for (int num : nums)
        {
            int temp = max(r1 + num, r2);
            r1 = r2;
            r2 = temp;
        }
        return r2;
    }
};
