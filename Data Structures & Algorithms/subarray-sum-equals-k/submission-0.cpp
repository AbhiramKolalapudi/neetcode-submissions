class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        int sum = 0;
        unordered_map<int,int> count;
        count[0]++;
        for (int i = 0; i < nums.size(); i++)
        {
            sum = sum + nums[i];
            res = res + count[sum - k];
            count[sum]++;
        }
        return res;
    }
};