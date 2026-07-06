class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {//so the basic idea is that we add each element to stack but before that we pop all elements smaller than it 
     //and then in the res array we give the value to the popped element as the difference of index of the greater element and the popped element
        vector<int> res(temperatures.size(), 0);
        stack<pair<int, int>> stack; //the pair is [temp,index] and the stack is a monotonically decreasing stack i.e always decreasing or equal values
        for (int i = 0; i < temperatures.size(); i++) 
        {
            int t = temperatures[i];
            while (!stack.empty() && t > stack.top().first) 
            {
                auto pair = stack.top();
                stack.pop();
                res[pair.second] = i - pair.second;
            }
            stack.push({t, i});
        }
        return res;
    }
};
