class Solution {
public:
    vector<vector<string>> ans;
    vector<int> col, diag1, diag2;

    void nQueens(vector<string>& board, int row, int n) {
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int j = 0; j < n; j++) {

            if (col[j] || diag1[row - j + n - 1] || diag2[row + j])
                continue;

            board[row][j] = 'Q';
            col[j] = 1;
            diag1[row - j + n - 1] = 1;
            diag2[row + j] = 1;

            nQueens(board, row + 1, n);

            board[row][j] = '.';
            col[j] = 0;
            diag1[row - j + n - 1] = 0;
            diag2[row + j] = 0;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        ans.clear();

        vector<string> board(n, string(n, '.'));

        col.assign(n, 0);
        diag1.assign(2 * n - 1, 0);
        diag2.assign(2 * n - 1, 0);

        nQueens(board, 0, n);

        return ans;
    }
};