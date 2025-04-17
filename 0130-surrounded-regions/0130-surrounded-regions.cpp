class Solution {
public:
    void dfs(vector<vector<char>>& board, int r, int c) {
        int rows = board.size();
        int cols = board[0].size();

        // Boundary and already visited check
        if (r < 0 || c < 0 || r >= rows || c >= cols || board[r][c] != 'O') 
            return;

        // Mark current cell as safe
        board[r][c] = '#';

        // Explore all 4 directions
        dfs(board, r + 1, c);
        dfs(board, r - 1, c);
        dfs(board, r, c + 1);
        dfs(board, r, c - 1);
    }

    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;

        int rows = board.size();
        int cols = board[0].size();

        // 1. Mark 'O's on the border and their connected regions
        for (int r = 0; r < rows; ++r) {
            if (board[r][0] == 'O') dfs(board, r, 0);
            if (board[r][cols - 1] == 'O') dfs(board, r, cols - 1);
        }
        for (int c = 0; c < cols; ++c) {
            if (board[0][c] == 'O') dfs(board, 0, c);
            if (board[rows - 1][c] == 'O') dfs(board, rows - 1, c);
        }

        // 2. Flip remaining 'O' to 'X' (captured), and '#' back to 'O'
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (board[r][c] == 'O') {
                    board[r][c] = 'X';
                } else if (board[r][c] == '#') {
                    board[r][c] = 'O';
                }
            }
        }
    }
};
