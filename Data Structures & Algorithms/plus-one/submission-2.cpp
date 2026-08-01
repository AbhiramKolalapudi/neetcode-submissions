class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        int rightmost = digits.size() - 1;
        while (rightmost >= 0)
        {
            if (digits[rightmost] == 9)
            {
                digits[rightmost] = 0;
                rightmost--;
            }
            else
            {
                digits[rightmost]++;
                return digits;
            }
        }
        //we have 999...
        vector<int> newdigits(digits.size()+1, 0);
        newdigits[0] = 1;
        return newdigits;
    }
};
