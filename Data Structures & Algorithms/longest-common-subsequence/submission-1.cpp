class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) 
    {//we make a 2d array in which the each row is a letter from text1 and each coloumn is a letter from text2
     //we start from bottom right and if they both match we have value as 1+diagonal element 
     //and if they dont we have max(down or right element) and we do that till we compute all values
     //the final ans will be the top right element 
     //for saving space instead of a 2d array, we are using a temperory 1d array.
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
