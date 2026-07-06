class Solution {
public:
    int rob(vector<int>& nums) 
    {// basically same as house robber 1 but the houses are arranged in a circle so we cant include both last and first house
     // so we just use the prev code as helper and run it on 2 array one without first element and one without last element and get the max out of them both 
     // also if array has only 1 element we return it as both the arrays will be empty
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
