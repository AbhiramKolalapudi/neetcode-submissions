class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0)
            return false;

        unordered_map<int, int> cardcount;
        priority_queue<int, vector<int>, greater<int>> smallest;

        for (int card : hand) {
            cardcount[card]++;
            smallest.push(card);
        }

        while (!smallest.empty()) {

            // Skip stale copies
            while (!smallest.empty() && cardcount[smallest.top()] == 0)
                smallest.pop();

            if (smallest.empty())
                break;

            int first = smallest.top();

            for (int i = first; i < first + groupSize; i++) {
                if (cardcount[i] == 0)
                    return false;

                cardcount[i]--;
            }
        }

        return true;
    }
};