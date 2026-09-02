class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> ans;

        if (s.empty() || words.empty())
            return ans;

        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;

        unordered_map<string,int> target;

        for (string w : words)
            target[w]++;

        for (int offset = 0; offset < wordLen; offset++) {

            unordered_map<string,int> window;

            int left = offset;
            int matched = 0;

            for (int right = offset; right + wordLen <= s.size(); right += wordLen) {

                string word = s.substr(right, wordLen);

                if (target.count(word)) {

                    window[word]++;
                    matched++;

                    while (window[word] > target[word]) {

                        string leftWord = s.substr(left, wordLen);
                        window[leftWord]--;
                        left += wordLen;
                        matched--;
                    }

                    if (matched == wordCount) {

                        ans.push_back(left);

                        string leftWord = s.substr(left, wordLen);
                        window[leftWord]--;
                        left += wordLen;
                        matched--;
                    }

                } else {

                    window.clear();
                    matched = 0;
                    left = right + wordLen;
                }
            }
        }

        return ans;
    }
};