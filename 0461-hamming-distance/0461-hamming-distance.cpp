class Solution {
public:
    int hammingDistance(int x, int y) {
        int xorResult = x ^ y;
        int count = 0;

        while (xorResult) {
            count += xorResult & 1;  // Check the last bit
            xorResult >>= 1;         // Shift right
        }

        return count;
    }
};
