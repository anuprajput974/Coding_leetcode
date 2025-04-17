class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow: INT_MIN / -1 = 2^31, which overflows
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        // Convert both numbers to long long before abs() to prevent overflow
        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);

        long long result = 0;

        while (a >= b) {
            long long temp = b, multiple = 1;

            while ((temp << 1) <= a) {
                temp <<= 1;
                multiple <<= 1;
            }

            a -= temp;
            result += multiple;
        }

        // If the signs are different, the result should be negative
        if ((dividend > 0) ^ (divisor > 0))
            result = -result;

        return result;
    }
};
