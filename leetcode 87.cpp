class Solution
{
public:
    unordered_map<string, bool> dp;

    bool solve(string s1, string s2)
    {

        if (s1 == s2)
            return true;

        if (s1.size() != s2.size())
            return false;

        string key = s1 + "|" + s2;

        if (dp.count(key))
            return dp[key];

        string a = s1;
        string b = s2;

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        if (a != b)
            return dp[key] = false;

        int n = s1.size();

        for (int i = 1; i < n; i++)
        {

            if (solve(s1.substr(0, i), s2.substr(0, i)) &&
                solve(s1.substr(i), s2.substr(i)))
                return dp[key] = true;

            if (solve(s1.substr(0, i), s2.substr(n - i)) &&
                solve(s1.substr(i), s2.substr(0, n - i)))
                return dp[key] = true;
        }

        return dp[key] = false;
    }

    bool isScramble(string s1, string s2)
    {
        return solve(s1, s2);
    }
};