class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq (26,0);
        for (char& c : s)
        {
            freq[c - 'a']++;
        }

        priority_queue<pair<int,char>> maxheap;
        for (int i = 0; i < 26; i++)
        {
            char temp = i + 'a';
            maxheap.push({freq[i], temp});
        }

        if (maxheap.top().first > (s.size() + 1) / 2)
            return "";

        string res(s.size(), ' ');
        int placed = 0;
        int idx = 0;
        while(!maxheap.empty())
        {
            auto max = maxheap.top();
            maxheap.pop();
            while (max.first > 0)
            {
                if (idx >= s.size())
                    idx = 1;
                res[idx] = max.second;
                idx = idx + 2;
                max.first--;
            }
        }
        return res;
    }
};