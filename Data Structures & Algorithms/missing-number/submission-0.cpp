class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {//every number appears twice i.e. once as index i and once in nums[i] and as nums.size() appears only once (only in nums[i] and not i) so we start with that and last remaining will be the missing number
        int res = nums.size();
        for (int i = 0; i < nums.size(); i++)
        {
            res ^= i ^ nums[i];
        }
        return res;
    }
};
