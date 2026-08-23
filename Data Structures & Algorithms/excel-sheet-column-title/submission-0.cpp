class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res;
        while(columnNumber > 0)
        {
            columnNumber--;
            int character = columnNumber % 26;
            res.push_back(character + 'A');
            columnNumber = columnNumber / 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};