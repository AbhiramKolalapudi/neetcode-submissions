class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;
        int total;
        while (l < r)
        {
            total = numbers[l] + numbers[r];
            if (total < target)
            {
                l++; 
                continue;
            }
            if (total > target)
            {
                r--; 
                continue;
            }
            return {l+1, r+1};
        }
        return {};
    }
};
