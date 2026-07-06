class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {//Floyd's Tortoise and Hare Cycle Detection Algorithm
     //basically in the array of size [0 ... n-1] we will have n elements without 0 so one of them will be reapeated, so we make this array into a graph
     //where we start from index 0 and then whatever the value is that will point to that index (notice that nothing points to index 0).
     //so finally we will have a cycle and the answer will be the starting point of that cycle and to find that starting point we use floyds.
     //the first part is finding the intersection point of fast and slow where fast moves twice as fast as slow i.e fast goes 2 points at a time and slow goes 1.
     //and after we find that intersection point we start another pointer slow2 from start and wherever slow2 and slow meet that point is the starting point of cycle.
     //(this can be proved with maths)
        int slow = 0;
        int fast = 0;
        while (true)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast)
                break;
        }
        
        int slow2 = 0;
        while (slow != slow2)
        {
            slow = nums[slow];
            slow2 = nums[slow2];
        }
        return slow;
        
    }
};
