class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    { // we iterate though intervals add it to res if its behind newinterval and if its not we add new interval to res and then add all elements remaining from intervals to res
      // and if its an overlapping interval we combine them by checking min of both for start and max of both for end
        vector<vector<int>> res;
        for (int i = 0; i < intervals.size(); i++)
        {
            if (newInterval[1] < intervals[i][0])
            {
                res.push_back(newInterval);
                res.insert(res.end(), intervals.begin() + i, intervals.end());
                return res;
            }
            else if (newInterval[0] > intervals[i][1])
            {
                res.push_back(intervals[i]);
            }
            else
            {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }
        res.push_back(newInterval);
        return res;
    }
};
