class Solution {
public:
    bool canPartition(vector<int>& nums) 
    {//basically we have a set consisting of all possible sums and at first we add 0 
    //and then we iterate through  nums and do nums[i] + s(each element of sums) 
    //and then we check if target is in sums and if yes return true
    //btw target is (sum of all elements in nums) / 2
    //the new_sums is just so that we dont add elements to the set which we are iterating through
        int sum = 0;
        for (int num : nums)
            sum = sum + num;
        
        if (sum%2 != 0)
            return false;
        
        int target = sum/2;
        unordered_set<int> sums;
        sums.insert(0);
        for (int i = 0; i < nums.size(); i++)
        {
            unordered_set<int> new_sums = sums;
            for (int s : sums)
            {
                if (!sums.count(s+nums[i]))
                    new_sums.insert(s+nums[i]);
            }
            sums = new_sums;
            if (sums.count(target))
                return true;
        }
        return false;
    }
};
