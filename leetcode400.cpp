
class Solution {
public:
    int findNthDigit(int n) {

        long long digitLength = 1;
        long long count = 9;
        long long start = 1;

        // Step 1: Find the group containing nth digit
        while (n > digitLength * count) {

            n -= digitLength * count;

            digitLength++;
            count *= 10;
            start *= 10;
        }

        // Step 2: Find the actual number
        start += (n - 1) / digitLength;

        // Step 3: Find the digit position
        string num = to_string(start);

        return num[(n - 1) % digitLength] - '0';
    }
};
l