class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_set <int> s;
        for (int n : nums)
        {
            s.insert(n);
        }
        int res = 0;
        for (int n : s)
        {
            if (s.count(n-1) == 0) //checking if its left most element
            {
                int i = 1; //count of sequence
                while (s.count(n+i)!=0)
                {
                    i++;
                }
                if (i > res) //checking if this count is highest
                    res = i;
            }
        }
        return res;
    }
};
