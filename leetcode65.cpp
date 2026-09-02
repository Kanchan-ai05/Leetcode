class Solution {
public:
    bool isNumber(string s) {

        bool seenDigit = false;
        bool seenDot = false;
        bool seenExponent = false;
        bool digitAfterExponent = true;

        for (int i = 0; i < s.size(); i++) {

            char c = s[i];

            if (isdigit(c)) {
                seenDigit = true;
                digitAfterExponent = true;
            }

            else if (c == '.') {

                if (seenDot || seenExponent)
                    return false;

                seenDot = true;
            }

            else if (c == 'e' || c == 'E') {

                if (seenExponent || !seenDigit)
                    return false;

                seenExponent = true;
                digitAfterExponent = false;
            }

            else if (c == '+' || c == '-') {

                if (i != 0 &&
                    s[i - 1] != 'e' &&
                    s[i - 1] != 'E')
                    return false;
            }

            else
                return false;
        }

        return seenDigit && digitAfterExponent;
    }
};