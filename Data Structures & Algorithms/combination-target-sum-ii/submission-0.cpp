class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        vector<vector<int>> res;
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, res, cur, 0);
        return res;
    }

private:
    void backtrack(vector<int>& nums, int target, vector<vector<int>>& res, vector<int>& cur, int i)
    {
        if (target == 0)
        {
            res.push_back(cur);
            return;
        }

        if (target < 0 || i >= nums.size())
        {
            return;
        }


        cur.push_back(nums[i]);
        backtrack(nums, target - nums[i], res, cur, i+1);

        cur.pop_back();
        while (i + 1 < nums.size() && nums[i] == nums[i+1])
            i++;
        backtrack(nums, target, res, cur, i + 1);
    }
};

