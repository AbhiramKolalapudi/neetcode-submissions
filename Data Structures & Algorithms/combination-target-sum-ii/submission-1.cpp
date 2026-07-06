class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {//we cannot repeat the same candidate again and also if there are for example 2 duplicates of same candidate we cant have 2 different combinations of including first and not including second and including second and not including first
     //eg. if target is 3 and candidates are 1,1,2 we cannot have 1,2 (the first 1) and 1,2 (the second 1) again.
     //so (take,take) is allowed, (take,skip) is allowed, (skip,skip) is allowed but (skip,take) is not so if are skipping one then we skip all
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
        backtrack(nums, target - nums[i], res, cur, i+1); //taking an element and going to next one

        cur.pop_back();
        while (i + 1 < nums.size() && nums[i] == nums[i+1])
            i++;
        backtrack(nums, target, res, cur, i + 1); //not taking one and skipping all the duplicates
    }
};

