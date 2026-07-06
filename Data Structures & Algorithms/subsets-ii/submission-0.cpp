class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        sort(nums.begin(), nums.end());
        helper(nums, 0, subset, res);
        return res;
    }

private:
    void helper(vector<int>& nums, int i, vector<int>& subset, vector<vector<int>>& res)
    {
        if (i >= nums.size()) //once i is out of range add subset to res
        {
            res.push_back(subset);
            return;
        }

        subset.push_back(nums[i]); //include ith element
        helper(nums, i+1, subset, res);
        subset.pop_back(); //dont include ith element
        while (i + 1 < nums.size() && nums[i] == nums[i+1])
            i++;
        helper(nums, i+1, subset, res);
        
    }
};
