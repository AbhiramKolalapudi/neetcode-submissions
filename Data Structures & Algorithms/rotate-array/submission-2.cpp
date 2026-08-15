class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        k = k % nums.size();
        reverse(0, nums.size() - 1, nums);
        reverse(0, k - 1, nums);
        reverse(k, nums.size() - 1, nums);
    }

private:
    void reverse(int start, int end, vector<int>& nums )
    {
        int mid;
        if ((end - start + 1) % 2 == 0)
            mid = (end - start + 1) / 2;

        else
            mid = (end - start) / 2;

        mid = start + mid;
        
        while (start < mid)
        {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }
};