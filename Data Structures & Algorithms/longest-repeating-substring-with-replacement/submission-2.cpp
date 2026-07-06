class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map <char, int> freqmap;
        int l = 0;
        int res = 0;
        for (int i = 0; i < s.length(); i++)
        {
            freqmap[s[i]] += 1;
            int maxfreq = 0;
            for (auto& m : freqmap)
            {
                maxfreq = max(maxfreq, m.second);
            }
            while (((i-l+1) - maxfreq) > k) //if the no of elements to be replaced exceeds k
            {
                freqmap[s[l]]--;
                l++;
            }
            res = max(res, (i-l+1));
        }
        return res;
    }
};
