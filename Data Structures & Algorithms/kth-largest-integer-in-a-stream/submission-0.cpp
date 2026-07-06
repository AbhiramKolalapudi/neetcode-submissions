class KthLargest {
private:
    priority_queue<int,vector<int>,greater<int>> minheap;
    int globalk;
public:
    KthLargest(int k, vector<int>& nums) 
    {
        globalk = k;
        for (int num: nums)
        {
            minheap.push(num);
            if (minheap.size() > globalk)
                minheap.pop();
        }
    }
    
    int add(int val) 
    {
        minheap.push(val);
        while(minheap.size() > globalk)
        {
            minheap.pop();
        }
        return minheap.top();
    }
};
