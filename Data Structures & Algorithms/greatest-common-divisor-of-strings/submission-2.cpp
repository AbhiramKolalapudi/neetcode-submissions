class Solution {
public:
    string gcdOfStrings(string str1, string str2) 
    {
        for (int i = min(str1.size(), str2.size()); i >= 1; i--)
        {
            if (isDivisor(str1, str2, i))
            {
                return str1.substr(0,i);
            }
        }
        return "";
    }

private:
    bool isDivisor(string str1, string str2, int l)
    {
        if (str1.size() % l != 0 || str2.size() % l != 0)
            return false;

        int f1 = str1.size() / l;
        int f2 = str2.size() / l;

        string base = str1.substr(0, l);

        string temp1 = "";
        string temp2 = "";

        for (int i = 0; i < f1; i++)
            temp1 += base;

        for (int i = 0; i < f2; i++)
            temp2 += base;

        return temp1 == str1 && temp2 == str2;
        
    }
};