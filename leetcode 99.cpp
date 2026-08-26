class Solution
{
public:
  TreeNode *First = nullptr;
  TreeNode *Second = nullptr;
  TreeNode *prev = nullptr;

  void inorder(TreeNode *root)
  {
    if (root == nullptr)
      return;

    inorder(root->left);
    if (prev && prev->val > root->val)
    {
      if (First == nullptr)
        First = prev;
      Second = root;
    }
    prev = root;
    inorder(root->right);
  }

  void recoverTree(TreeNode *root)
  {
    inorder(root);
    swap(First->val, Second->val);
  }
};
