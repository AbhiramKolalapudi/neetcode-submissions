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
                break;
            }
        }
        if (rightmost < 0)
        {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
