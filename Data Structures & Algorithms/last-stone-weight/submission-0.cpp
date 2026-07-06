class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> heap;
        for (int stone : stones)
            heap.push(stone);
        
        while(heap.size() > 1)
        {
            int first = heap.top();
            heap.pop();
            int second = heap.top();
            heap.pop();
            if (first > second)
                heap.push(first - second);
            else if ( first < second)
                heap.push(second - first);
        }
        if (!heap.empty())
            return heap.top();
        return 0;
    }
};
