class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {// the idea is the minimum rate will be 1 so that time will be sum of all elements
    // and max rate will be max element so that time is number of elements 
    // as the rate is between 1 and max element, instead of searching all rates we do binary search and in the end we get the minimum rate that will give us time < h
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        while (l < r)
        {
            int m = l + (r - l)/2;
            int t = 0;
            for (auto& p : piles)
            {
                t = t + (m + p - 1) / m;
            }
            if (t > h)
                l = m + 1;
            else 
                r = m;

        }
        return r;
    }
};
