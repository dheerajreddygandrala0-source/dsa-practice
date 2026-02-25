class Solution {
public:
    bool issafe(vector<vector<char>>& board, int row, int col, char dig) {
        
        // Check row
        for (int j = 0; j < 9; j++) {
            if (board[row][j] == dig)
                return false;
        }

        // Check column
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == dig)
                return false;
        }

        // Check 3x3 box
        int srow = (row / 3) * 3;
        int scol = (col / 3) * 3;

        for (int i = srow; i < srow + 3; i++) {
            for (int j = scol; j < scol + 3; j++) {
                if (board[i][j] == dig)
                    return false;
            }
        }

        return true;
    }

    bool helper(vector<vector<char>>& board, int row, int col) {
        
        // If reached beyond last row, puzzle solved
        if (row == 9)
            return true;

        // Compute next cell
        int nextrow, nextcol;
        if (col == 8) {
            nextrow = row + 1;
            nextcol = 0;
        } else {
            nextrow = row;
            nextcol = col + 1;
        }

        // Skip filled cells
        if (board[row][col] != '.') {
            return helper(board, nextrow, nextcol);
        }

        // Try digits 1-9
        for (char dig = '1'; dig <= '9'; dig++) {
            if (issafe(board, row, col, dig)) {

                board[row][col] = dig;

                if (helper(board, nextrow, nextcol))
                    return true;

                board[row][col] = '.'; // backtrack
            }
        }

        return false; // no valid digit found
    }

    void solveSudoku(vector<vector<char>>& board) {
        helper(board, 0, 0);
    }
};
