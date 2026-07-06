class Solution {
public:
//so the basic idea of backtracking is that we build combination until we reach invalid case after which we backtrack(remove an element or undo choice) and then try with another combination.
//in this qn we always go with index starting from the current one (we dont go to prev index) so that we dont repeat combinations i.e. we dont get 2,2,3 and 2,3,2.
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res; //result vector of vectors of int
        vector<int> cur; //cur vector of int
        backtrack(nums, target, res, cur, 0);//call backtrack with index 0 and res gets updated
        return res;//return res
    }

private:
    void backtrack(vector<int>& nums, int target, vector<vector<int>>& res, vector<int>& cur, int i)
    {
        if (target == 0)//valid path i.e. reached target, so push cur to res
        {
            res.push_back(cur);
            return;
        }
        
        if (target < 0 || i >= nums.size())//invalid path i.e. either sum went above target or index went out of range, so end that path
        {
            return;
        }

        cur.push_back(nums[i]);//we always push ith element until we reach an invalid path 
        backtrack(nums, target - nums[i], res, cur, i);

        cur.pop_back();//when we reach an invalid path, we remove one element and try again this time by increasing i i.e. going to next element in nums
        backtrack(nums, target, res, cur, i+1);

    }
};
