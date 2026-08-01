class Solution {
public:
    double myPow(double x, int n) 
    {
        double res;
        res = findpow(x, n);
        return res;
    }
private:
    double findpow(double x, int n)
    {
        if (n == 0)
            return 1;
        else if (n == 1)
            return x;
        else if (n < 0)
            return 1 / findpow(x, -n);
            
        else
        {
            if (n % 2 == 0)
                return findpow(x, n/2) * findpow(x, n/2);
            else
                return x * findpow(x, n/2) * findpow(x, n/2);
        }
    }
};
