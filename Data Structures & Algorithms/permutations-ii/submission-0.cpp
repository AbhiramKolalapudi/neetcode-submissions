class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        vector<vector<int>> res;
        vector<int> perm;
        unordered_map<int, int> count;

        for (int& num : nums)
            count[num]++;

        backtrack(nums, res, count, perm);
        return res;
    }

private:
    void backtrack(vector<int>& nums, vector<vector<int>>& res, unordered_map<int, int>& count, vector<int>& perm)
    {
        if (perm.size() == nums.size())
        {
            res.push_back(perm);
            return;
        }

        for (auto& [num, cnt] : count)
        {
            if (cnt > 0)
            {
                perm.push_back(num);
                cnt--;
                backtrack(nums, res, count, perm);
                perm.pop_back();
                cnt++;
            }
        }
    }
};
