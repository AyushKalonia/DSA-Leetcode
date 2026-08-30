class Solution {
public:
    vector<vector<string>> ans;
    vector<string> board;

    vector<bool> col;
    vector<bool> diag1;
    vector<bool> diag2;

    void backtrack(int row, int n) {
        // All queens are placed
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++) {

            // Check column and diagonals
            if (col[c] || diag1[row + c] || diag2[row - c + n - 1])
                continue;

            // Place queen
            board[row][c] = 'Q';
            col[c] = true;
            diag1[row + c] = true;
            diag2[row - c + n - 1] = true;

            // Move to next row
            backtrack(row + 1, n);

            // Backtrack: remove queen
            board[row][c] = '.';
            col[c] = false;
            diag1[row + c] = false;
            diag2[row - c + n - 1] = false;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        board = vector<string>(n, string(n, '.'));

        col = vector<bool>(n, false);

        // There are 2*n - 1 diagonals
        diag1 = vector<bool>(2 * n - 1, false);
        diag2 = vector<bool>(2 * n - 1, false);

        backtrack(0, n);

        return ans;
    }
};