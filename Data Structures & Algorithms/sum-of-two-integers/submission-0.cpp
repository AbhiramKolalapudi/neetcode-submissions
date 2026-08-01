class Solution {
public:
    int getSum(int a, int b) 
    {//basically & will give us carry and ^ will give us addition without carry
        while (b != 0) {
            int carry = (a & b) << 1;
            a ^= b;
            b = carry;
        }
        return a;
    }
};