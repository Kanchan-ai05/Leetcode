class Solution {
public:
    NestedInteger deserialize(string s) {
        int i = 0;
        return helper(s, i);
    }

    NestedInteger helper(string &s, int &i) {

        // Case 1: Current value is an integer
        if (s[i] == '-') {
            // Negative number
        }

        if (s[i] != '[') {
            int num = 0;
            int sign = 1;

            if (s[i] == '-') {
                sign = -1;
                i++;
            }

            while (i < s.size() && isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                i++;
            }

            return NestedInteger(num * sign);
        }

        // Case 2: Current value is a nested list
        NestedInteger list;
        i++; // Skip '['

        while (i < s.size() && s[i] != ']') {

            if (s[i] == ',') {
                i++;
            }
            else {
                list.add(helper(s, i));
            }
        }

        i++; // Skip ']'

        return list;
    }
};