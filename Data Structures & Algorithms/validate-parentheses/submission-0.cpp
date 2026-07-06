class Solution {
public:
    bool isValid(string s) {
        stack<char> validpar;
        for (char c : s)
        {
            if (c == '(' || c == '[' || c == '{')
                validpar.push(c);
            else if (validpar.empty())
                return false;
            else if (c == ')')
            {
                if (validpar.top() != '(')
                {
                    return false;
                }
                validpar.pop();
            }
            else if (c == ']')
            {
                if (validpar.top() != '[')
                {
                    return false;
                }
                validpar.pop();
            }
            else if (c == '}')
            {
                if (validpar.top() != '{')
                {
                    return false;
                }
                validpar.pop();
            }
            else 
                return false;
        }
        if (!validpar.empty())
            return false;
        return true;
    }
};
