class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size());
        int pre = 1;
        int post = 1;
        res[0] = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            pre = pre * nums[i-1];
            res[i] = pre;
        }

        for (int j = (nums.size() - 2); j >=0; j--)
        {
            post = post * nums[j+1];
            res[j] = res[j] * post;
        }
        return res;
        //we iterate through the input array twice,
        //the first time we store product of prefix of nums[i] in res[i]
        //the second time we multiply product of postfix of nums[i] in res[i]
    }
};
