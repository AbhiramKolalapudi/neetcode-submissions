class Solution {
public:
    int rob(vector<int>& nums) 
    { //so basically we use bottom up dynamic programming where we make an array from starting and every element value is max of either (its value + n-2 value) or n-1 value and at the end return the last value
      //but instead of computing the entire array we just compute the values in r1 for n-1 and r2 for n-1 to save storage and at last return r2
        int r1 = 0;
        int r2 = 0;
        for (int num : nums)
        {
            int temp = max(r1 + num, r2);
            r1 = r2;
            r2 = temp;
        }
        return r2;
    }
};
