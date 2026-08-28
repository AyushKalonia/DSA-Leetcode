class Solution {
public:
    bool backtrack(vector<vector<char>>& board, const string& word, int idx, int x, int y) {
        if (idx == word.size() - 1) return true; // last char is matched

        int m = board.size();
        int n = board[0].size();
        char temp = board[x][y];
        board[x][y] = '#';
        // up, right, down, left
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {-1, 0, 1, 0};

        for (int i = 0; i < 4; ++i) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if (new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && board[new_x][new_y] == word[idx + 1]) {
                if (backtrack(board, word, idx + 1, new_x, new_y)) {
                    return true;
                }
            }
        }

        board[x][y] = temp;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        // pruning by freq (start)
        unordered_map<char, int> board_char_count;
        for (const auto& row : board) {
            for (char c : row) {
                board_char_count[c]++;
            }
        }

        unordered_map<char, int> word_char_count;
        for (auto c: word) {
            word_char_count[c]++;
        }

        for (auto [ch, count] : word_char_count) {
            if (board_char_count[ch] < count) return false;
        }

        if (board_char_count[word.back()] < board_char_count[word.front()]) {
            reverse(word.begin(), word.end());
        }
        // pruning by freq (end)


        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == word[0]) {
                    if (backtrack(board, word, 0, i, j)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};