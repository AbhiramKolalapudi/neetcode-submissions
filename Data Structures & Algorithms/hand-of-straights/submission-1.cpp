class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) 
    {
        if (hand.size() % groupSize != 0)
            return false;
        unordered_map<int,int> cardcount;
        priority_queue<int, vector<int>, greater<int>> smallest;

        for (int card : hand)
            cardcount[card]++;

        for (auto &p : cardcount)
            smallest.push(p.first);

        while (!smallest.empty())
        {
            int first = smallest.top();
            for (int i = first; i < first + groupSize; i++)
            {
                if (cardcount[i] == 0)
                    return false;
                else
                {
                    cardcount[i]--;
                    if (cardcount[i] == 0)
                    {
                    
                        if (i != smallest.top())
                            return false;

                        smallest.pop();
                    }
                }
            }
        }
        return true;
    }
};
