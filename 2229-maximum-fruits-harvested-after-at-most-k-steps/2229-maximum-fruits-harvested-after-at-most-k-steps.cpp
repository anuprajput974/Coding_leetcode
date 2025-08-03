class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        vector<int> pos(n), sum(n + 1, 0);
        
        for (int i = 0; i < n; ++i) {
            pos[i] = fruits[i][0];
            sum[i + 1] = sum[i] + fruits[i][1];
        }

        int ans = 0;

        // Case 1: Go left, then right
        for (int x = 0; x <= k; ++x) {
            int leftMost = startPos - x;
            int rightMost = startPos + max(0, k - 2 * x);
            
            int l = lower_bound(pos.begin(), pos.end(), leftMost) - pos.begin();
            int r = upper_bound(pos.begin(), pos.end(), rightMost) - pos.begin();
            
            ans = max(ans, sum[r] - sum[l]);
        }

        // Case 2: Go right, then left
        for (int x = 0; x <= k; ++x) {
            int rightMost = startPos + x;
            int leftMost = startPos - max(0, k - 2 * x);
            
            int l = lower_bound(pos.begin(), pos.end(), leftMost) - pos.begin();
            int r = upper_bound(pos.begin(), pos.end(), rightMost) - pos.begin();
            
            ans = max(ans, sum[r] - sum[l]);
        }

        return ans;
    }
};
