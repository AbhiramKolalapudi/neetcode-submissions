class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        vector<int> count(26,0);

        for (char& task : tasks)
        {
            count[task - 'A']++;
        }

        priority_queue<int> maxheap; //stores count of all tasks

        for (int c : count)
        {
            if (c > 0)
                maxheap.push(c);
        }

        queue<pair<int,int>> q; //we take the highest count task and remove it and add it to queue along with the time when it will be ready again i.e. current time + n

        int time = 0;
        while (!maxheap.empty() || !q.empty())
        {
            time++;

            if (maxheap.empty())
                time = q.front().second;
            else
            {
                int cnt = maxheap.top() - 1;
                maxheap.pop();
                if (cnt > 0)
                    q.push({cnt, time + n});
            }
            if (!q.empty() && q.front().second == time)
            {
                maxheap.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};
