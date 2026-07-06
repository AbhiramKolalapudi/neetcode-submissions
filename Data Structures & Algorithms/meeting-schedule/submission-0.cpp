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

class Solution 
{
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) 
        {
            return a.start < b.start;
        });
        Interval temp = intervals[0];
        bool first = true;
        for (auto& i : intervals) 
        {
            if (first)
            {
                first = false;
                continue;
            }
            if (i.start < temp.end)
            {
                return false;
            }
            else
                temp = i;
        }
        return true;
    }
};
