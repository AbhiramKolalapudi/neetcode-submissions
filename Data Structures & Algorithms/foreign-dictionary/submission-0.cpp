class Solution {
public:
unordered_map<char,vector<char>> adj;
unordered_map<char,bool> visit; //false -> visited, true -> in current path
string res;
    string foreignDictionary(vector<string>& words) 
    { //topological sort usign dfs
        for (string& word : words)
        {
            for (char c : word)
                adj[c];
        }
        for (int i = 0; i < words.size() - 1; i++)
        {
            string w1 = words[i];
            string w2 = words[i+1];
            int minlen = min(w1.length(), w2.length());
            if (w1.length() > w2.length() && w1.substr(0,minlen) == w2)
                return "";
            for (int j = 0; j < minlen; j++)
            {
                if (w1[j] != w2[j])
                {
                    adj[w1[j]].push_back(w2[j]);
                    break;
                }   

            }
        }
        for (auto& p : adj)
        {
            if (dfs(p.first))
                return "";
        }
        reverse(res.begin(), res.end());
        return res;
    }

private:
    bool dfs(char c)
    {
        if (visit.count(c))
            return visit[c];

        visit[c] = true;

        for (char nei : adj[c])
        {
            if (dfs(nei))
                return true;
        }

        visit[c] = false;
        res.push_back(c);
        return false;
    }
};
