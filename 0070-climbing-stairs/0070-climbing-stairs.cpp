class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;

        int a = 1, b = 2;
        int current;

        for (int i = 3; i <= n; ++i) {
            current = a + b;
            a = b;
            b = current;
        }

        return b;
    }
};
