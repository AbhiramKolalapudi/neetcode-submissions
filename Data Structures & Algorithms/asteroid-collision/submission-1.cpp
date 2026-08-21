class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int a : asteroids)
        {
            if (a > 0)
            {
                st.push(a);
            }
            else
            {
                while (!st.empty() && st.top() > 0 && st.top() < -a)
                {
                    st.pop();
                }

                if (st.empty() || st.top() < 0)
                {
                    st.push(a);
                }
                else if (st.top() == -a)
                {
                    st.pop();
                }
            }
        }

        vector<int> res;

        while (!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};