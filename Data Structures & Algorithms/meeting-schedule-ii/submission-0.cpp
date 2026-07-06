/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> start;
        vector<int> end;
        for (const auto& i : intervals) 
        {
            start.push_back(i.start);
            end.push_back(i.end);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int count = 0;
        int maxcount = 0;
        int s = 0;
        int e = 0;
        while (s < start.size())
        {
            if (start[s] < end[e])
            {
                count++;
                s++;
            }
            else
            {
                count--;
                e++;
            }
            maxcount = max(maxcount, count);
        }
        return maxcount;
    }
};
