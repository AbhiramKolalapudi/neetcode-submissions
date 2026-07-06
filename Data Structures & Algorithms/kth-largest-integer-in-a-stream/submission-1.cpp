class KthLargest {
private:
    priority_queue<int,vector<int>,greater<int>> minheap; //this will make a minheap (default for priority queue is max heap)
    int globalk;
public:
    KthLargest(int k, vector<int>& nums) 
    {
        globalk = k;
        for (int num: nums) //we only store k elements in the minheap and the min value will be the kth smallest element
        {
            minheap.push(num);
            if (minheap.size() > globalk)
                minheap.pop();
        }
    }
    
    int add(int val) 
    {//even when we are adding elements we see if it exceeds capacity of k and then pop an element until we get k elements and the min one will be kth largest
        minheap.push(val);
        while(minheap.size() > globalk)
        {
            minheap.pop();
        }
        return minheap.top();
    }
};
