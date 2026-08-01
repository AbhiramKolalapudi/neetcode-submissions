class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {//this works as a ^ a = 0 and a ^ 0 = a so if we xor the entire array then every duplicate number will cancel out and last remaining will be the single number
        int res = 0;
        for (int num : nums)
            res ^= num;
        return res;
    }
};
