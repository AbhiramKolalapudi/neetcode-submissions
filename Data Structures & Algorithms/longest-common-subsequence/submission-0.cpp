class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<int> curr(text2.size()+1, 0);
        vector<int> prev(text2.size()+1, 0);

        for (int i = text1.size()-1; i >= 0; i--)
        {
            for (int j = text2.size()-1; j >= 0; j--)
            {
                if (text1[i] == text2[j])
                    curr[j] = prev[j+1] + 1;

                else
                    curr[j] = max(prev[j], curr[j+1]);
            }
            prev = curr;
        }
        return curr[0];
    }
};
