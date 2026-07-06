class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) 
    {//basically we sort all the cars in order of position in descending order and calculate at what time they will reach the target
     //and then we check if they cars collide and become a single fleet by checking if the target reaching time is lesser than target reaching time of the car on top of stack
     //i.e. we see if any car will collide with a right side car and if they collide u dont add them to stack as they will become a single fleet else you add them to stack
     //and the next car will again compare to the top of the stack car and at last the result will be stack size
        vector<pair<int, int>> pair;
        for (int i = 0; i < position.size(); i++) 
            pair.push_back({position[i], speed[i]});

        sort(pair.rbegin(), pair.rend());

        stack<double> stack;

        for (auto& p : pair)
        {
            double t = (double)(target - p.first) / p.second;
            if (stack.empty())
                stack.push(t);
            else
            {
                if (t > stack.top())
                    stack.push(t);
            }
        }
        return stack.size();

    }
};
