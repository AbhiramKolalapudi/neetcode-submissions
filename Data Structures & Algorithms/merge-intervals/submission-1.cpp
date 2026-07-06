class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> output;
        output.push_back(intervals[0]);

        for (auto& i : intervals)
        {
            if (i[0] <= output.back()[1])
                output.back()[1] = max(output.back()[1], i[1]);

            else
                output.push_back({i[0], i[1]});
        }
        return output;
    }
};
