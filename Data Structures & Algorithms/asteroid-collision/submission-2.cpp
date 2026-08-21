class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int a : asteroids)
        {
            if (a > 0) //positive means pop to stack
            {
                st.push(a);
            }
            else //negative
            {
                while (!st.empty() && st.top() > 0 && st.top() < -a) //destroy all the possible positive astroids
                {
                    st.pop();
                }

                if (st.empty() || st.top() < 0) //if its the only remaining element or others are also negative
                {
                    st.push(a);
                }
                else if (st.top() == -a) //both same size so destroy both
                {
                    st.pop();
                }
                else //it gets destroyed
                {
                    ;
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