class Solution {
public:
    string simplifyPath(string path) {
        vector<string> folders;
        stringstream ss(path);
        string part;

        while (getline(ss, part, '/')) {

            if (part == "" || part == ".") {
                continue;
            }

            if (part == "..") {
                if (!folders.empty()) {
                    folders.pop_back();
                }
            }
            else {
                folders.push_back(part);
            }
        }

        string ans = "";

        for (string folder : folders) {
            ans += "/" + folder;
        }

        if (ans == "") {
            ans = "/";
        }

        return ans;
    }
};