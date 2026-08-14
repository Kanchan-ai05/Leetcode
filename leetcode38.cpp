class Solution {
public:
    string countAndSay(int n) {
        string s = "1";

        for (int i = 1; i < n; i++) {
            string next = "";

            for (int j = 0; j < s.length(); ) {
                int count = 0;
                char ch = s[j];

                while (j < s.length() && s[j] == ch) {
                    count++;
                    j++;
                }

                next += to_string(count);
                next += ch;
            }

            s = next;
        }

        return s;
    }
};