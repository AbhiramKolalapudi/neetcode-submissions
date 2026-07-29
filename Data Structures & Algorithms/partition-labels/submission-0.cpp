class Solution {
public:
    vector<int> partitionLabels(string s) 
    {//we store the last index of every character in the first for loop
     //in the second for loop we first get end of the current substring which will be the max of last index of all elements in the current substring
     //and when end is reached we add the size to res and go to next substring
        unordered_map<char,int> lastindex;
        for (int i = 0; i < s.length(); i++)
        {
            lastindex[s[i]] = i;
        }

        int size = 0;
        int end = 0;
        vector<int> res;
        for (int i = 0; i < s.length(); i++)
        {
            size++;
            end = max(end, lastindex[s[i]]);
            if (i == end)
            {
                res.push_back(size);
                size = 0;
            }
        }
        return res;
    }
};
