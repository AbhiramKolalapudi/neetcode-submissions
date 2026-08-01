class Solution {
public:
    string multiply(string num1, string num2) 
    {
        if (num1 == "0" || num2 == "0")
            return "0";
        vector<int> res(num1.size() + num2.size(), 0);
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for (int i = 0; i < num1.size(); i++)
        {
            for (int j = 0; j < num2.size(); j++)
            {
                int n1 = num1[i] - '0';
                int n2 = num2[j] - '0';
                int product = n1 * n2;
                int idx = i + j;
                res[idx] += product;
                res[idx+1] += res[idx] / 10;
                res[idx] = res[idx] % 10;
            }
        }
        string ans;

        int i = res.size() - 1;

        while (i > 0 && res[i] == 0)
            i--;

        for (; i >= 0; i--)
            ans.push_back(res[i] + '0');
        
        return ans;
    }
};
