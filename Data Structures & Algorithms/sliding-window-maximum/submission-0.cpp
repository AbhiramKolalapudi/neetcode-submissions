class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    { //we have a double ended queue in which we can add/remove elements from both front and back
      //in this deque we keep adding elements' index and the max element is always the front one for each window
      //when we are adding elements to the deque we remove all the elements from the back that are lesser than this element
        vector<int> output(nums.size() - k + 1);
        deque<int> q;
        int l = 0;
        int r = 0; //start with window size 1 and then start increasing it until r = k and then start getting output[l]
        while (r < nums.size())
        {
            while (!q.empty() && nums[q.back()] < nums[r]) //remove elements from back that are lesser than this element i.e nums[r]
                q.pop_back();
                
            q.push_back(r); //now add the element's index i.e. r

            if (l > q.front()) //remove the front element if its not in window anymore
                q.pop_front();

            if ((r + 1) >= k) //when window size becomes k, start moving l also
            {
                output[l] = nums[q.front()];
                l++;
            }
            r++;
        }
        return output;
    }
};
