class Solution {
public:
    int evalRPN(vector<string>& tokens) 
    {
        stack<int> stk;
        for (auto& t : tokens)
        {
            if (t == "+")
            {
                int num1 = stk.top();
                stk.pop();
                int num2 = stk.top();
                stk.pop();
                stk.push(num1 + num2);
            }
            else if (t == "*")
            {
                int num1 = stk.top();
                stk.pop();
                int num2 = stk.top();
                stk.pop();
                stk.push(num1 * num2);
            }
            else if (t == "-")
            {
                int num1 = stk.top();
                stk.pop();
                int num2 = stk.top();
                stk.pop();
                stk.push(num2 - num1);
            }
            else if (t == "/")
            {
                int num1 = stk.top();
                stk.pop();
                int num2 = stk.top();
                stk.pop();
                stk.push(num2 / num1);
            }
            else
            {
                int num = stoi(t);
                stk.push(num);
            }
            
        }
        return (stk.top());
    }
};
