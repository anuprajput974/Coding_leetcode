class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            count += n & 1;  // Check last bit
            n >>= 1;         // Shift right
        }
        return count;
    }
};
