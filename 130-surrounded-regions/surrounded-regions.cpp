class Solution {
public:
    vector<vector<int>> direction{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    void dfs(vector<vector<char>>& board, vector<vector<int>>& memo, int i,
             int j) {
        int n = board.size();
        int m = board[0].size();

        // boundary + visited + only 'O'
        if (i < 0 || j < 0 || i >= n || j >= m || board[i][j] != 'O' ||
            memo[i][j] != -1)
            return;

        // mark visited
        memo[i][j] = 0;

        // explore all 4 directions
        for (auto& dir : direction) {
            int ni = i + dir[0];
            int nj = j + dir[1];
            dfs(board, memo, ni, nj);
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if (n == 0)
            return;
        int m = board[0].size();

        // initialize memo with -1
        vector<vector<int>> memo(n, vector<int>(m, -1));

        // LEFT and RIGHT columns
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O' && memo[i][0] == -1)
                dfs(board, memo, i, 0);

            if (board[i][m - 1] == 'O' && memo[i][m - 1] == -1)
                dfs(board, memo, i, m - 1);
        }

        // TOP and BOTTOM rows
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O' && memo[0][j] == -1)
                dfs(board, memo, 0, j);

            if (board[n - 1][j] == 'O' && memo[n - 1][j] == -1)
                dfs(board, memo, n - 1, j);
        }

        // update board based on memo
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && memo[i][j] == -1) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};