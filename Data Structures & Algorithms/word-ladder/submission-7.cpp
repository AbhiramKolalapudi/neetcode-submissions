class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        if (endWord.empty() || find(wordList.begin(), wordList.end(), endWord) == wordList.end())
            return 0;
        
        unordered_map<string,vector<string>> neighbours;
        wordList.push_back(beginWord);

        for (string& word : wordList)
        {
            for (int i = 0; i < word.size(); i++)
            {
                string pattern = word;
                pattern[i] = '*';
                neighbours[pattern].push_back(word);
            }
        }

        queue<string> q;
        unordered_set<string> visit;
        q.push(beginWord);
        visit.insert(beginWord);
        int distance = 1;

        while(!q.empty())
        {
            int qsize = q.size();
            for (int i = 0; i < qsize; i++)
            {
                string word = q.front();
                q.pop();
                visit.insert(word);
                if (word == endWord)
                    return distance;
                for (int i = 0; i < word.size(); i++)
                {
                    string pattern = word;
                    pattern[i] = '*';
                    for (string& s : neighbours[pattern])
                    {
                        if (visit.count(s))
                            continue;
                        q.push(s);
                    }
                }
            }
            distance++;
        }
        return 0;
    }
};
