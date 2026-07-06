class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        // Edge case
        if (n == 1) return nums[0];
        
        // Two cases: exclude last OR exclude first
        return max(helper(nums, 0, n - 2),
                   helper(nums, 1, n - 1));
    }

private:
    int helper(vector<int>& nums, int start, int end) {
        int r1 = 0, r2 = 0;
        
        for (int i = start; i <= end; i++) {
            int temp = max(r1 + nums[i], r2);
            r1 = r2;
            r2 = temp;
        }
        
        return r2;
    }
};