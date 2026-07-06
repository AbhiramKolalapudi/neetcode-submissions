class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        stack<pair<int, int>> st; // {start_index, height}
        int res = 0;

        for (int i = 0; i < heights.size(); i++)
        {
            int start = i;

            while (!st.empty() && st.top().second >= heights[i])
            {
                int index = st.top().first;
                int height = st.top().second;
                st.pop();

                res = max(res, height * (i - index));
                start = index;
            }

            st.push({start, heights[i]});
        }

        while (!st.empty())
        {
            int index = st.top().first;
            int height = st.top().second;
            st.pop();

            res = max(res, height * ((int)heights.size() - index));
        }

        return res;
    }
};