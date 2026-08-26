class Solution
{
public:
    vector<string> ans;

    void backtrack(string &s, int index, vector<string> &path)
    {

        if (path.size() == 4)
        {
            if (index == s.size())
            {
                ans.push_back(path[0] + "." + path[1] + "." +
                              path[2] + "." + path[3]);
            }
            return;
        }

        for (int len = 1; len <= 3; len++)
        {

            if (index + len > s.size())
                break;

            string part = s.substr(index, len);

            if (part.size() > 1 && part[0] == '0')
                continue;

            if (stoi(part) > 255)
                continue;

            path.push_back(part);

            backtrack(s, index + len, path);

            path.pop_back();
        }
    }

    vector<string> restoreIpAddresses(string s)
    {

        vector<string> path;

        backtrack(s, 0, path);

        return ans;
    }
};