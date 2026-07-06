class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        //same logic as combinations 2, where if we take an element we can go to next one but if we are skipping it we have to skip all duplicates too
        vector<vector<int>> res;
        vector<int> subset;
        sort(nums.begin(), nums.end());
        helper(nums, 0, subset, res);
        return res;
    }

private:
    void helper(vector<int>& nums, int i, vector<int>& subset, vector<vector<int>>& res)
    {
        if (i >= nums.size())
        {
            res.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        helper(nums, i+1, subset, res);
        subset.pop_back(); 
        while (i + 1 < nums.size() && nums[i] == nums[i+1])
            i++;
        helper(nums, i+1, subset, res);
        
    }
};
