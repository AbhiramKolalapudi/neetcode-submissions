class Solution {
public:
    int reverse(int x) {
        //basically to always stay within the 32 bit limit, we check if all digits except last is greater (or lesser for -ve) all digits except last for max (or min) and then if yes then we return 0 else if they are equal we compare last digits
        int max = 2147483647; // 2^31 - 1
        int min = -2147483648; // -2^31
        int res = 0;
        while (x)
        {
            int digit = x % 10;
            x = x / 10;
            if (res > (max/10) || res == (max/10) && digit > (max%10))
                return 0;

            if (res < (min/10) || res == (min/10) && digit < (min%10))
                return 0;
            
            res = res*10 + digit;
        }
        return res;
    }
};
