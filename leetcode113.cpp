
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void dfs(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return;
        }

        path.push_back(root->val);
        targetSum -= root->val;

        // Check whether this is a leaf node
        if (root->left == nullptr && root->right == nullptr) {
            if (targetSum == 0) {
                ans.push_back(path);
            }
        } else {
            dfs(root->left, targetSum);
            dfs(root->right, targetSum);
        }

        // Backtrack: remove current node
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return ans;
    }
};
