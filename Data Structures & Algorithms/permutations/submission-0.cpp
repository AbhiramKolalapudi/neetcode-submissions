class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> res;
        vector<bool> pick(nums.size(), false);
        vector<int> perm;
        backtrack(nums, res, pick, perm);
        return res;
    }

private:
    void backtrack(vector<int>& nums, vector<vector<int>>& res, vector<bool>& pick, vector<int>& perm)
    {
        if (perm.size() == nums.size())
        {
            res.push_back(perm);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (!pick[i])
            {
                perm.push_back(nums[i]);
                pick[i] = true;
                backtrack(nums, res, pick, perm);
                perm.pop_back();
                pick[i] = false;
            }
        }
    }
};
