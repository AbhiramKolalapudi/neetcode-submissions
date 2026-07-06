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
    

    void dfs(vector<vector<char>>& board, TrieNode* node, string& word, vector<string>& res,  int r, int c)
    {
        if (r < 0 || r >= ROWS || c < 0 || c >= COLS || board[r][c] == '#') //if r or c out of range or if already visited and is marked with ('#') then end that path
            return;

        int idx = board[r][c] - 'a';
        if (!node->children[idx]) //if that letter is not there in children then end that path
            return;

        node = node->children[idx]; //move to the child node corresponding to board[r][c] in the trie

        word.push_back(board[r][c]); //and add that letter to word
        if (node->isEnd) //if its end push that word to res and make isEnd false so that we dont add the same words again and again
        {
            res.push_back(word);
            node->isEnd = false;
        }
        board[r][c] = '#'; //mark the current letter on board
        dfs(board, node, word, res, r - 1, c); //call dfs for all 4 directions of the board to check the next letter
        dfs(board, node, word, res, r + 1, c); //note that we went down a level in the trie so we are checking in the next level 
        dfs(board, node, word, res, r, c - 1);
        dfs(board, node, word, res, r, c + 1);
        board[r][c] = word.back(); //backtrack by unmarking the letter on board and popping last letter from word string
        word.pop_back();
    }

public:
    int ROWS, COLS;
    Solution()
    {
        root = new TrieNode();
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) 
    {
        //first we make a trie and inserted all the words into that trie (insert fn and trie struct def and all same code from trie qns)
        for (auto& str : words)
        {
            insert(str);
        }
        //next just like the word search 1 qn, we iterate through the board and see if any word exists and if they do then store them in res array
        ROWS = board.size(); 
        COLS = board[0].size();
        vector<string> res;
        for (int r = 0; r < ROWS; r++)
        {
            for (int c = 0; c < COLS; c++)
            {
                int idx = board[r][c] - 'a';
                if (root->children[idx]) //if the child exists for that letter on board then do the dfs search
                {
                    string word; //empty string in which we add each letter for every dfs call
                    dfs(board, root, word, res, r, c);
                }
            }
        }
        return res;
    }
};
