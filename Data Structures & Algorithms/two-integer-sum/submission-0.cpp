class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> checkvalues;
        for (int i=0; i < nums.size(); i++)
        {
            checkvalues[nums[i]] = i;
        }
        for (int i=0; i < nums.size(); i++)
        {
            int diff = target - nums[i];
            if (checkvalues.count(diff) && checkvalues[diff] != i)
                return {i, checkvalues[diff]};
        }
        return {};
    }
};
