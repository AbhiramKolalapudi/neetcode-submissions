class Solution {
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
    void dfs(vector<vector<char>>& board, TrieNode* node, string& word, vector<string>& res,  int r, int c)
    {
        if (r < 0 || r >= ROWS || c < 0 || c >= COLS || board[r][c] == '#')
            return;

        int idx = board[r][c] - 'a';
        if (!node->children[idx])
            return;

        node = node->children[idx];
        word.push_back(board[r][c]);
        if (node->isEnd)
        {
            res.push_back(word);
            node->isEnd = false;
        }
        board[r][c] = '#';
        dfs(board, node, word, res, r - 1, c);
        dfs(board, node, word, res, r + 1, c);
        dfs(board, node, word, res, r, c - 1);
        dfs(board, node, word, res, r, c + 1);
        board[r][c] = word.back();
        word.pop_back();
    }

public:
    int ROWS, COLS;
    Solution()
    {
        root = new TrieNode();
    }
    void insert(string word) {
        TrieNode* node = root;

        for (char ch : word) {
            int idx = ch - 'a';
            if (node->children[idx] == nullptr)
                node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->isEnd = true;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) 
    {
        for (auto& str : words)
        {
            insert(str);
        }
        ROWS = board.size(); 
        COLS = board[0].size();
        vector<string> res;
        for (int r = 0; r < ROWS; r++)
        {
            for (int c = 0; c < COLS; c++)
            {
                string word = "";
                int idx = board[r][c] - 'a';
                if (root->children[idx])
                    dfs(board, root, word, res, r, c);
            }
        }
        return res;
    }
};
