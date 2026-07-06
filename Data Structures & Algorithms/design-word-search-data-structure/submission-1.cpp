class WordDictionary {
private:
    struct TrieNode {
        TrieNode* children[26];
        bool isEnd;

        TrieNode() {
            isEnd = false;
            for (int i = 0; i < 26; i++)
                children[i] = nullptr;
        }
    };

    TrieNode* root;

public:
    WordDictionary() {
        root = new TrieNode();        
    }
    
    void addWord(string word) {
        TrieNode* node = root;

        for (char ch : word) 
        {
            int idx = ch - 'a';
            if (node->children[idx] == nullptr)
                node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->isEnd = true;
    }
    bool search(string word) 
    {
        return dfs(word, 0, root);
    }
    
    bool dfs(string word, int j, TrieNode* start) 
    {
        TrieNode* node = start;

        for (int i = j; i < word.size(); i++) 
        {
            char ch = word[i];
            if (ch == '.')
            {
                for (TrieNode* child : node->children)
                {
                    if (child != nullptr && dfs(word, i + 1, child))
                        return true;
                }
                return false;
            }
            else
            {
                int idx = ch - 'a';
                if (node->children[idx] == nullptr)
                    return false;
                node = node->children[idx];
            }
        }
        return node->isEnd;
    }
};
