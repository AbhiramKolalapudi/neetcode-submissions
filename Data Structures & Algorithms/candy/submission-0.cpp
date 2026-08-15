class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<pair<int, int>> children;
        vector<int> candies (ratings.size(), 0);
        for (int i = 0; i < ratings.size(); i++)
        {
            children.push_back({ratings[i], i});
        }
        sort(children.begin(), children.end());
        for (auto& c : children)
        {
            int idx = c.second;
            int left = 0;
            int right = 0;
            if (idx > 0 && ratings[idx] > ratings[idx - 1])
                left = candies[idx - 1];

            if (idx < ratings.size() - 1 && ratings[idx] > ratings[idx + 1])
                right = candies[idx + 1];

            candies[idx] = max(left, right) + 1;

        }
        int res = accumulate(candies.begin(), candies.end(), 0);
        return res;
    }
};