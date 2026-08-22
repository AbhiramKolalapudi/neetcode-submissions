class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 0;
        for (int r = 0; r < nums.size(); r++)
        {
            if (nums[r] != nums[r-1] || r == 0)
            {
                nums[l] = nums[r];
                l++;
            }
        }
        return l;
    }
};