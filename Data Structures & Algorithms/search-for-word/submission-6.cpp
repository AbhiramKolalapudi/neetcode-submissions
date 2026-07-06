class Solution {
public:
    int ROWS, COLS;
    bool exist(vector<vector<char>>& board, string word) {
        ROWS = board.size(); //total rows in board
        COLS = board[0].size(); //total cols in board

        for (int r = 0; r < ROWS; r++)
        {
            for (int c = 0; c < COLS; c++)
            {
                if (dfs(board, word, r, c, 0)) //do the search, starting from everywhere on the board and if found anywhere then return true.
                    return true;
            }
        }
        return false;//if not found anywhere then return false.
    }

private:
    bool dfs(vector<vector<char>>& board, string& word, int r, int c, int i)
    {
        if (i == word.size())//i goes thru index of word and increases for every search, so when it is equal to size i.e. went past the word, then return true
            return true;
        
        if (r < 0 || r >= ROWS || c < 0 || c >= COLS || board[r][c] != word[i] || board[r][c] == '#') //if r and c are out of range or the letter is wrong or the letter is already visited ('#'), then return false
            return false;

        board[r][c] = '#';//mark the current letter visited with '#'.

        bool res = ( dfs(board, word, r + 1, c, i + 1) || dfs(board, word, r - 1, c, i + 1) || 
                     dfs(board, word, r, c + 1, i + 1) || dfs(board, word, r, c - 1, i + 1) ); //now see if the next letter(i + 1) exists anywhere in r +- 1 or c +- 1 i.e. all 4 directions (up, down, left, right).

        board[r][c] = word[i];//unmark the letter after the search (backtracking) so that other paths can use this cell.
        //until the true or false condition is met, the recursive calls of dfs will be going on and once false is reached it stops that path but still checks other paths
        //but if true condition is met then original res becomes true.
        return res; //res will be true if in any of the paths we meet the true condition.
    }
};
