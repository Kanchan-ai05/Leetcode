class Solution {
public:
    int divide(int dividend, int divisor) {

        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        long long a = llabs((long long)dividend);
        long long b = llabs((long long)divisor);

        long long quotient = 0;

        while (a >= b) {

            long long value = b;
            long long multiple = 1;

            while ((value << 1) <= a) {
                value <<= 1;
                multiple <<= 1;
            }

            a -= value;
            quotient += multiple;
        }

        bool negative = (dividend < 0) != (divisor < 0);

        return negative ? -quotient : quotient;
    }
};