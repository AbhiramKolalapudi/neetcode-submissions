class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(),intervals.end());
        int res = 0;
        vector<int> temp;
        temp = intervals[0];
        bool first = true;
        for (auto& i : intervals) 
        {
            if (first)
            {
                first = false;
                continue;
            }
            if (i[0] < temp[1])
            {
                res++;
                if (i[1] < temp[1])
                    temp = i;
            }
            else
                temp = i;
        }
        return res;
    }
};
