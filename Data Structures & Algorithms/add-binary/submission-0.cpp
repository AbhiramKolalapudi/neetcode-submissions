class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int carry = 0;

        int i = a.size() - 1, j = b.size() - 1;
        while (i >= 0 || j >= 0 || carry > 0) 
        {
            int digitA;
            int digitB;
            if (i >= 0)
                digitA = a[i] - '0';
            else
                digitA = 0;

            if (j >= 0)
                digitB = b[j] - '0';
            else
                digitB = 0;

            int total = digitA + digitB + carry;
            res += (total % 2) + '0';
            carry = total / 2;

            i--;
            j--;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};