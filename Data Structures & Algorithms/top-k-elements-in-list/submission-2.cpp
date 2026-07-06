class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count; //normal count map 
        for (const auto& n : nums)
        {
            count[n]++;
        }
        
        vector<vector<int>> count_list(nums.size() + 1); //vector of elements where the index is their count 
        for (const auto& c : count)     //i.e. at count_list[x] we have list of elements of count x
        {
            count_list[c.second].push_back(c.first);
        }
        
        vector<int> result; //vector of elements from highest to lowest freq.
        for (int i = count_list.size() - 1; i > 0; i--)
        {
            for (int n : count_list[i])
            {
                result.push_back(n);
                if(result.size() == k) //will stop building the result vector when size k is achieved
                {
                    return result;
                }
            }
        }
        return {};
    }
};
