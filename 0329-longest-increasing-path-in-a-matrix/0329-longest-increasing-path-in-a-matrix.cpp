class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int maxLen = 0;

        // Directions: up, down, left, right
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        function<int(int, int)> dfs = [&](int i, int j) -> int {
            if (dp[i][j] != 0) return dp[i][j];
            int maxPath = 1;

            for (auto& [dx, dy] : directions) {
                int ni = i + dx, nj = j + dy;
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && matrix[ni][nj] > matrix[i][j]) {
                    maxPath = max(maxPath, 1 + dfs(ni, nj));
                }
            }

            dp[i][j] = maxPath;
            return dp[i][j];
        };

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                maxLen = max(maxLen, dfs(i, j));

        return maxLen;
    }
};
