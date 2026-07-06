class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> result; //{"1,1,1,0,..." : [abc,cba],... }
        for (const auto& s : strs)
        {
            vector<int> count(26,0); //[1,1,1,0,0,0,...] for abc
            for (const auto& c : s)
            {
                count[c - 'a']++;
            }
            string k = to_string(count[0]); //converting vector to string
            for (int i=1; i<26; i++)
            {
                k = k + ',' + to_string(count[i]);
            }
            result[k].push_back(s); //pushing s to value vector<string> of key k
        }
        vector<vector<string>> group; //pushing all the values(vector<string>) of result
        for (const auto& x : result)
        {
            group.push_back(x.second);
        }
        return group;
    }
};
