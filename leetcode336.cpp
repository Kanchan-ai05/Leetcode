class Solution
{
public:
    bool isPalindrome(string &s, int left, int right)
    {
        while (left < right)
        {
            if (s[left++] != s[right--])
                return false;
        }
        return true;
    }

    vector<vector<int>> palindromePairs(vector<string> &words)
    {

        unordered_map<string, int> mp;

        for (int i = 0; i < words.size(); i++)
            mp[words[i]] = i;

        vector<vector<int>> ans;

        for (int i = 0; i < words.size(); i++)
        {

            string word = words[i];

            for (int j = 0; j <= word.size(); j++)
            {

                string prefix = word.substr(0, j);
                string suffix = word.substr(j);

                if (isPalindrome(word, 0, j - 1))
                {

                    string rev = suffix;
                    reverse(rev.begin(), rev.end());

                    if (mp.count(rev) && mp[rev] != i)
                        ans.push_back({mp[rev], i});
                }

                if (j != word.size() && isPalindrome(word, j, word.size() - 1))
                {

                    string rev = prefix;
                    reverse(rev.begin(), rev.end());

                    if (mp.count(rev) && mp[rev] != i)
                        ans.push_back({i, mp[rev]});
                }
            }
        }

        return ans
    }
};