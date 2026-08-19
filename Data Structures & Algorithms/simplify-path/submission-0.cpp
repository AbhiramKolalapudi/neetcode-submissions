class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string temp;
        string res;
        for (char c : path)
        {
            if (c == '/')
            {
                if (!temp.empty())
                {
                    if (temp == "..")
                    {
                        if (!st.empty())
                            st.pop();
                    }
                    else if (temp == ".")
                        ;
                    else
                        st.push(temp);
                    temp = "";
                }

            }
            else
                temp = temp + c;
        }
        if (!temp.empty())
        {
            if (temp == "..")
            {
                if (!st.empty())
                    st.pop();
            }
            else if (temp == ".")
                ;
            else
                    st.push(temp);
        }
        
        while (!st.empty())
        {
            temp = st.top();
            st.pop();
            res = "/" + temp + res;
        }

        return res.empty() ? "/" : res;
    }
};