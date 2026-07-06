class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {// basically we compute curmin and curmax which is the max and min product value of a subarray that ends at current index
     // the main reason for storing curmin is because the curmin might be negative and when we get a negative number and multiply with it we might get a number bigger than curmax
        int res = nums[0];
        int curMin = 1, curMax = 1;

        for (int num : nums) 
        {
            int tmp = curMax * num;
            curMax = max(max(num * curMax, num * curMin), num);
            curMin = min(min(tmp, num * curMin), num);
            res = max(res, curMax);
        }
        return res;
    }
};
