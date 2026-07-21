class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) 
    { //bottom up dp 
      //each row is including each element in nums and each column is the target 
      //(instead of vector we use map as the target can become negative too)
      //so basically whenever we reach a row, for every element in the previous row i.e. dp we add/subtract the current row element to get value
      //and then the result will be added to nextdp[num] (which is zero in the beginning)
      //in the end the result is at dp[target]
        unordered_map<int, int> dp;
        dp[0] = 1;

        for (int num : nums)
        {
            unordered_map<int, int> nextdp;
            for (auto& x : dp)
            {
                nextdp[x.first + num] += x.second;
                nextdp[x.first - num] += x.second;
            }
            dp = nextdp;
        }
        return dp[target];
    }
};
