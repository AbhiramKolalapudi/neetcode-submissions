class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        int sumgas = 0;
        int sumcost = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            sumgas = sumgas + gas[i];
            sumcost = sumcost + cost[i];
        }

        if (sumcost > sumgas) //this means the circuit is not even possible even if we start at any place
            return -1;

        else //else it is possible, as it is possible we are just trying to find starting index, so from starting if total = sum of (gas[i] - cost[i]) goes negative at i then starting point will i + 1.
        {
            int total = 0;
            int res = 0;
            for (int i = 0; i < gas.size(); i++)
            {
                total = total + (gas[i] - cost[i]);
                if (total < 0)
                {
                    total = 0;
                    res = i + 1;
                }
            }
            return res;
        }
    }
};
