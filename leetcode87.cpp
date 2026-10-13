class Solution {
public:

    unordered_map<string, bool> dp;

    bool solve(string s1, string s2) {

        
        if (s1 == s2)
            return true;

        
        if (s1.length() != s2.length())
            return false;

        string key = s1 + "#" + s2;

        
        if (dp.find(key) != dp.end())
            return dp[key];

        
        string a = s1;
        string b = s2;

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        if (a != b)
            return dp[key] = false;

        int n = s1.length();

        
        for (int k = 1; k < n; k++) {

            
            if (solve(s1.substr(0, k),
                      s2.substr(0, k)) &&
                solve(s1.substr(k),
                      s2.substr(k))) {

                return dp[key] = true;
            }

            
            if (solve(s1.substr(0, k),
                      s2.substr(n - k)) &&
                solve(s1.substr(k),
                      s2.substr(0, n - k))) {

                return dp[key] = true;
            }
        }

        return dp[key] = false;
    }

    bool isScramble(string s1, string s2) {
        return solve(s1, s2);
    }
};