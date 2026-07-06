class MinStack {
public:
    std::stack<int> stack;
    std::stack<int> minStack;
    MinStack() 
    {

    }
    
    void push(int val) 
    {
        stack.push(val);
        if (!minStack.empty())
        {
            if (val < minStack.top())
                minStack.push(val);
            else
                minStack.push(minStack.top());
        }
        else 
            minStack.push(val);
    }
    
    void pop() 
    {
        stack.pop();
        minStack.pop();    
    }
    
    int top() 
    {
        return stack.top();
    }
    
    int getMin() 
    {
        return minStack.top();
    }
};
