class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) 
    {//first we sort both intervals and queries but for queries we reserve the original index
    //then we iterate through sortedqueries and for each query we add all the eligible intervals by seeing their start and along with their length to a minheap
    //then from the minheap we pop one by one if they are not eligible by their ends as if their end is not eligible for current query then it wont be eligible for the next queries which will be higher
    //then we take the smallest length interval and uut its length in res
    //the main logic is that for a query if the start of interval is eligible then for future queries also the intervals's start will be eligible hence dont clear the minheap after every iteration
    //and for a query if the end of interval is not eligible then for future queries also the interval's end wont be eligible hence pop the ineligible ones

        sort(intervals.begin(),intervals.end());
        vector<pair<int,int>> sortedqueries;
        for (int i = 0; i < queries.size(); i++)
            sortedqueries.push_back({queries[i], i});

        sort(sortedqueries.begin(),sortedqueries.end());

        vector<int> res(queries.size(), -1);
        priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int,int>>> minheap;
        int i = 0;

        for (auto &[query, idx] : sortedqueries)
        {
            while (i < intervals.size() && intervals[i][0] <= query)
            {
                int start = intervals[i][0];
                int end = intervals[i][1];
                int length = end - start + 1;
                minheap.push({length, end});
                i++;
            }

            while (!minheap.empty() && minheap.top().second < query) 
                minheap.pop();

            if (!minheap.empty())
                res[idx] = minheap.top().first;
        }
        return res;
    }
};
