class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> keystore;
    TimeMap() 
    {    
    }
    
    void set(string key, string value, int timestamp) 
    {
        keystore[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) 
    { //binary search to get the exact timestamp and if not then return the highest value less than the timestamp
        auto& values = keystore[key];
        int l = 0;
        int r = values.size()-1;
        string result = "";
        while (l <= r)
        {
            int m = l + (r - l)/2;
            if (values[m].first == timestamp)
                return values[m].second;
            if (values[m].first > timestamp)
                r = m - 1;
            else
            {
                l = m + 1;
                result = values[m].second;
            }
        }
        return result;
    }
};
