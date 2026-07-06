class MedianFinder {
public:
//the basic idea is that we manage 2 heaps (one for storing all large elements and one for small elements i.e somewhat below and above median)
//so all elements of smallheap <= largeheap
//the smallheap will be a max heap and largeheap will be a min heap so that getting max value from smallheap and min value from largeheap will be O(1) time.
//now to calculate the median, if size of both are same then it will be avg of max value from smallheap and min value from largeheap,
//and if the size is not same then the median is the extra element of any of the heaps.
    priority_queue<int, vector<int>, less<int>> smallHeap; //max heap
    priority_queue<int, vector<int>, greater<int>> largeHeap; //min heap
    MedianFinder() {

    }
//for adding elements to the heaps, we always first push it into smallheap then we check if the max element in smallheap is greater than the min element of largeheap, if so we move that element to largeheap.
//next we check size balancing i.e. we check if the sizes of both differ by at max 1 (if the size differ by one it means odd elements and if they are same it means even elements).
//if the sizes differ by more than 1 then we move top element (max in smallheap and min in largeheap) of one heap to the other one.
    void addNum(int num) {
        smallHeap.push(num);

        if (!largeHeap.empty() && smallHeap.top() > largeHeap.top())
        {
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }

        if (smallHeap.size() > largeHeap.size() + 1)
        {
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }

        if (largeHeap.size() > smallHeap.size() + 1)
        {
            smallHeap.push(largeHeap.top());
            largeHeap.pop();            
        }
    }
    
    double findMedian() {
        if (smallHeap.size() == largeHeap.size()) //both size same so return the avg of top elements
            return ((smallHeap.top() + largeHeap.top()) / 2.0);

        else if (smallHeap.size() > largeHeap.size()) //return top element of the bigger size heap
            return (smallHeap.top());

        else if (smallHeap.size() < largeHeap.size())
            return (largeHeap.top());
    }
};
