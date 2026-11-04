
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return build(1, n);
    }

    vector<TreeNode*> build(int start, int end) {
        vector<TreeNode*> ans;

        if (start > end) {
            ans.push_back(nullptr);
            return ans;
        }

        for (int rootVal = start; rootVal <= end; rootVal++) {
            vector<TreeNode*> leftTrees = build(start, rootVal - 1);
            vector<TreeNode*> rightTrees = build(rootVal + 1, end);

            for (TreeNode* left : leftTrees) {
                for (TreeNode* right : rightTrees) {
                    TreeNode* root = new TreeNode(rootVal);
                    root->left = left;
                    root->right = right;
                    ans.push_back(root);
                }
            }
        }

        return ans;
    }
};
