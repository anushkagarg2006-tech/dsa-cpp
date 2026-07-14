class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char ch = board[i][j];
                if (ch == '.')
                    continue;
                if (!issafe(board, ch,i, j))
                    return false;
            }
        }
        return true;
    }
    bool issafe(vector<vector<char>>& board, char ch, int i, int j) {
        for (int a = 0; a < 9; a++) {
            if (a!=i&&board[a][j] == ch)
                return false;

            if (a!=j&&board[i][a] == ch)
                return false;

            int boxRow = 3 * (i / 3) + a / 3;
            int boxCol = 3 * (j / 3) + a % 3;
            if (boxRow!=i&&boxCol!=j&&board[boxRow][boxCol] == ch)
                return false;
        }
        return true;
    }
};