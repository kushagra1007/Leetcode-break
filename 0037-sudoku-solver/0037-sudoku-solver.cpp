class Solution {
public:

    bool helper(vector<vector<char>>& board,
                int pos,
                vector<vector<bool>>& row,
                vector<vector<bool>>& col,
                vector<vector<bool>>& box) {

        // All cells filled
        if (pos == 81) {
            return true;
        }

        int r = pos / 9;
        int c = pos % 9;

        // Already filled
        if (board[r][c] != '.') {
            return helper(board, pos + 1, row, col, box);
        }

        // Find box number
        int b = (r / 3) * 3 + (c / 3);

        for (int d = 1; d <= 9; d++) {

            if (row[r][d] || col[c][d] || box[b][d]) {
                continue;
            }

            // Place digit
            board[r][c] = char('0' + d);

            row[r][d] = true;
            col[c][d] = true;
            box[b][d] = true;

            if (helper(board, pos + 1, row, col, box)) {
                return true;
            }

            // Backtrack
            board[r][c] = '.';

            row[r][d] = false;
            col[c][d] = false;
            box[b][d] = false;
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {

        vector<vector<bool>> row(9, vector<bool>(10, false));
        vector<vector<bool>> col(9, vector<bool>(10, false));
        vector<vector<bool>> box(9, vector<bool>(10, false));

        // Initialize existing digits
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {

                if (board[r][c] != '.') {

                    int d = board[r][c] - '0';
                    int b = (r / 3) * 3 + (c / 3);

                    row[r][d] = true;
                    col[c][d] = true;
                    box[b][d] = true;
                }
            }
        }

        helper(board, 0, row, col, box);
    }
};